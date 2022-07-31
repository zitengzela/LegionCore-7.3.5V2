
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/compiler/cpp/cpp_helpers.h>
#include <google/protobuf/compiler/cpp/cpp_file.h>
#include <boost/filesystem/operations.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

bool ParseFromIstreamWithDescriptorPool(google::protobuf::FileDescriptorProto& proto, std::istream* input)
{
    google::protobuf::io::IstreamInputStream zero_copy_input(input);
    google::protobuf::io::CodedInputStream decoder(&zero_copy_input);
    decoder.SetExtensionRegistry(google::protobuf::DescriptorPool::generated_pool(), google::protobuf::MessageFactory::generated_factory());
    return proto.ParseFromCodedStream(&decoder) && decoder.ConsumedEntireMessage() && input->eof();
}

// bool SerializeWithDescriptorPool(google::protobuf::FileDescriptorProto& proto, std::istream* output)
// {
    // google::protobuf::io::ZeroCopyOutputStream zero_copy_output(output);
    // google::protobuf::io::CodedOutputStream decoder(&zero_copy_output);
    // decoder.SetExtensionRegistry(google::protobuf::DescriptorPool::generated_pool(), google::protobuf::MessageFactory::generated_factory());
    // return proto.SerializeToCodedStream(&decoder) && decoder.ConsumedEntireMessage() && output->eof();
// }

static std::string base64_encode(const std::string &in) {

    std::string out;

    int val=0, valb=-6;
    for (char c : in) {
        val = (val<<8) + c;
        valb += 8;
        while (valb>=0) {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if (valb>-6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    while (out.size()%4) out.push_back('=');
    return out;
}

static std::string base64_decode(const std::string &in) {

    std::string out;

    std::vector<int> T(256,-1);
    for (int i=0; i<64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i; 

    int val=0, valb=-8;
    for (char c : in) {
        if (T[c] == -1) break;
        val = (val<<6) + T[c];
        valb += 6;
        if (valb>=0) {
            out.push_back(char((val>>valb)&0xFF));
            valb-=8;
        }
    }
    return out;
}

int main(int argc, char* argv[])
{
    // first collect files
    boost::filesystem::directory_iterator end;
    std::set<std::string> files;
    for (boost::filesystem::directory_iterator itr(boost::filesystem::current_path()); itr != end; ++itr)
        if (boost::filesystem::is_regular_file(itr->status()))
        {
            if (itr->path().extension().string().find(".protoc") != std::string::npos)
            {
                std::string fileName = itr->path().string();
                std::ifstream is(fileName.c_str(), std::ifstream::binary);
                 if (!is.good())
                {
                    fprintf(stderr, "!in.good() %s\n", fileName.c_str());
                    continue;
                }

                // get length of file:
                is.seekg(0, is.end);
                int length = is.tellg();
                is.seekg(0, is.beg);

                std::string s;
                s.resize(length);
                is.read(&s[0], length);

                std::string decoded = base64_decode(s);

                // std::string fileNameN = (fileName + "c");

                // fprintf(stderr, "fileNameN %s\n", fileNameN.c_str());
                // std::ofstream ofs;
                std::ostringstream ss;
                // ofs.open(fileNameN.c_str(), std::ofstream::out);
                static const int kBytesPerLine = 40;
                for (int i = 0; i < decoded.size(); i += kBytesPerLine) {
                    ss << "\n  \"";
                    ss << (google::protobuf::compiler::cpp::EscapeTrigraphs(google::protobuf::CEscape(decoded.substr(i, kBytesPerLine))));
                    ss << "\"";
                }
                // ofs << ss.str().c_str();
                // ofs.close();
                ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(ss.str().c_str(), decoded.size());
            }
        }

    // Second collect files
    boost::filesystem::directory_iterator end2;
    std::set<std::string> files2;
    for (boost::filesystem::directory_iterator itr(boost::filesystem::current_path()); itr != end2; ++itr)
        if (boost::filesystem::is_regular_file(itr->status()))
        {
            if (itr->path().extension().string().find(".protoc") != std::string::npos)
            {
                fprintf(stderr, "%s\n", itr->path().string().c_str());
                files2.insert(itr->path().string());
            }
        }

    // its time to hack private members
    auto pool = google::protobuf::DescriptorPool::internal_generated_pool();
    void* mutex_ = *reinterpret_cast<char**>(pool);
    void* fallback_database_ = *(reinterpret_cast<void**>(pool) + 1);
    *reinterpret_cast<void**>(pool) = nullptr; // mutex_
    *(reinterpret_cast<void**>(pool) + 1) = nullptr; // fallback_database_

    std::vector<std::pair<google::protobuf::FileDescriptorProto, bool>> descProtos;
    std::set<std::string> parsed;
    std::list<std::string> parsedSorted;
    // then load everything into descriptor pool
    fprintf(stderr, "files.size() %i\n", files.size());

    // for (int i = 0; i < files.size(); ++i)
    {
        //fprintf(stderr, "files %i\n", i);

        for (std::string const& fileName : files2)
        {
            // if (parsed.count(fileName))
            // {
                // //fprintf(stderr, "parsed.count %s\n", fileName.c_str());
                // continue;
            // }

            // std::ifstream is(fileName.c_str(), std::ifstream::binary);
             // if (!is.good())
            // {
                // fprintf(stderr, "!in.good() %s\n", fileName.c_str());
                // continue;
            // }

            // // get length of file:
            // is.seekg(0, is.end);
            // int length = is.tellg();
            // is.seekg(0, is.beg);

            // std::string s;
            // s.resize(length);
            // is.read(&s[0], length);

            // std::string decoded = base64_decode(s);

            // // char* buffer = new char [length];
            // // memcpy(&s[0], buffer, length);

            // // fprintf(stderr, "fileName %s %s\n", fileName.c_str(), decoded.c_str());
            // // fprintf(stderr, "bytecode length %i fileName %s\n", length, fileName.c_str());
            // google::protobuf::FileDescriptorProto fileDescProto;
            // // if (ParseFromIstreamWithDescriptorPool(fileDescProto, &is))
            // if (fileDescProto.ParseFromString(decoded.c_str()))
            // {
                // // std::ofstream ofs;
                // // ofs.open("test.txt", std::ofstream::out);

                // // std::string serialized;
                // // printer.PrintToString(fileDescProto, &serialized);
                // // fileDescProto.SerializeToString(&serialized);
                // // fprintf(stderr, "fileDescProto.ParseFromString %s\n", serialized.c_str());

                // // ofs << serialized;
                // // ofs.close();
  
                // if (google::protobuf::FileDescriptor const* fileDesc = pool->BuildFile(fileDescProto))
                // {
                    // // std::ofstream ofs;
                    // // ofs.open("test.txt", std::ofstream::out | std::ofstream::app);

                    // // google::protobuf::compiler::cpp::Options file_options;
                    // // google::protobuf::compiler::cpp::FileGenerator file_generator(fileDesc, file_options);
                    // // google::protobuf::io::OstreamOutputStream zero_copy_input(&ofs);
                    // // // google::protobuf::io::CodedOutputStream decoder(&zero_copy_input);
                    // // google::protobuf::io::Printer printer(&zero_copy_input, '$');
                    // // // file_generator.GenerateHeader(&printer);
                    // // file_generator.GenerateSource(&printer);

                    // for (int i = 0; i < fileDesc->extension_count(); ++i)
                    // {
                        // google::protobuf::FieldDescriptor const* extension = fileDesc->extension(i);
                        // switch (extension->type())
                        // {
                            // case google::protobuf::internal::WireFormatLite::TYPE_ENUM:
                                // google::protobuf::internal::ExtensionSet::RegisterEnumExtension(
                                    // google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->containing_type()),
                                    // extension->number(),
                                    // extension->type(),
                                    // extension->is_repeated(),
                                    // extension->is_packed(),
                                    // [](int){ return true; });
                                // break;
                            // case google::protobuf::internal::WireFormatLite::TYPE_MESSAGE:
                            // case google::protobuf::internal::WireFormatLite::TYPE_GROUP:
                                // google::protobuf::internal::ExtensionSet::RegisterMessageExtension(
                                    // google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->containing_type()),
                                    // extension->number(),
                                    // extension->type(),
                                    // extension->is_repeated(),
                                    // extension->is_packed(),
                                    // google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->extension_scope()));
                                // break;
                            // default:
                                // google::protobuf::internal::ExtensionSet::RegisterExtension(
                                    // google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->containing_type()),
                                    // extension->number(),
                                    // extension->type(),
                                    // extension->is_repeated(),
                                    // extension->is_packed());
                                // break;
                        // }
                    // }

                    // parsed.insert(fileName);
                    // parsedSorted.push_back(fileName);
                // }
            // }
            // else
                // fprintf(stderr, "Not Parce %s\n", fileName.c_str());
                    parsedSorted.push_back(fileName);
        }
    }

    // and finally rebuild all protos in a new pool with fully resolved dependencies and extensions
    google::protobuf::DescriptorPool pool2;
    fprintf(stderr, "parsedSorted.size() %i\n", parsedSorted.size());
    for (std::string const& fileName : parsedSorted)
    {
        // fprintf(stderr, "fileName %s\n", fileName.c_str());
        std::ifstream is(fileName.c_str(), std::ifstream::binary);
        if (!is.good())
        {
            fprintf(stderr, "!in.good() %s\n", fileName.c_str());
            continue;
        }

        // get length of file:
        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        std::string s;
        s.resize(length);
        is.read(&s[0], length);

        std::string decoded = base64_decode(s);

        // char* buffer = new char [length];
        // memcpy(&s[0], buffer, length);

        google::protobuf::FileDescriptorProto fileDescProto;
        if (fileDescProto.ParseFromString(decoded.c_str()))
        // if (ParseFromIstreamWithDescriptorPool(fileDescProto, &is))
        {
            fprintf(stderr, "ParseFromString\n");
            if (google::protobuf::FileDescriptor const* fileDesc = pool2.BuildFile(fileDescProto))
            {
                fprintf(stderr, "BuildFile %s\n", fileName.c_str());
                boost::filesystem::create_directories(boost::filesystem::path(fileDesc->name()).parent_path());
                std::ofstream f(fileDesc->name());
                f << fileDesc->DebugString() << std::endl;
                f.close();
            }
        }
    }

    // unhack to free memory
    *reinterpret_cast<void**>(pool) = mutex_;
    *(reinterpret_cast<void**>(pool) + 1) = fallback_database_;

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}

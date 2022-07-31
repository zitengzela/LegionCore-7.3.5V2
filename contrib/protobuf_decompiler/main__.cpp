
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite.h>
#include <boost/filesystem/operations.hpp>
#include <fstream>
#include <iostream>
#include <string>

bool ParseFromIstreamWithDescriptorPool(google::protobuf::FileDescriptorProto& proto, std::istream* input)
{
    google::protobuf::io::IstreamInputStream zero_copy_input(input);
    google::protobuf::io::CodedInputStream decoder(&zero_copy_input);
    decoder.SetExtensionRegistry(google::protobuf::DescriptorPool::generated_pool(), google::protobuf::MessageFactory::generated_factory());
    fprintf(stderr, "ParseFromIstreamWithDescriptorPool %i %i %i \n", proto.MergeFromCodedStream(&decoder), decoder.ConsumedEntireMessage(), input->eof());
    return proto.MergeFromCodedStream(&decoder) && decoder.ConsumedEntireMessage() && input->eof();
    //return true;
}

int main(int argc, char* argv[])
{
    // first collect files
    boost::filesystem::directory_iterator end;
    std::set<std::string> files;
    for (boost::filesystem::directory_iterator itr(boost::filesystem::current_path()); itr != end; ++itr)
        if (boost::filesystem::is_regular_file(itr->status()))
            if (itr->path().extension().string().find(".protoc") != std::string::npos)
            {
                fprintf(stderr, "%s\n", itr->path().string());
                files.insert(itr->path().string());
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
    for (int i = 0; i < files.size(); ++i)
    {
        for (std::string const& fileName : files)
        {
            if (parsed.count(fileName))
                continue;

            std::ifstream in;
            in.open(fileName.c_str(), std::ios::binary | std::ios::in);
            if (!in.good())
            {
                fprintf(stderr, "%s\n", fileName.c_str());
                continue;
            }

            google::protobuf::FileDescriptorProto fileDescProto;
            if (ParseFromIstreamWithDescriptorPool(fileDescProto, &in))
            {
                if (google::protobuf::FileDescriptor const* fileDesc = pool->BuildFile(fileDescProto))
                {
                    for (int i = 0; i < fileDesc->extension_count(); ++i)
                    {
                        google::protobuf::FieldDescriptor const* extension = fileDesc->extension(i);
                        switch (extension->type())
                        {
                            case google::protobuf::internal::WireFormatLite::TYPE_ENUM:
                                google::protobuf::internal::ExtensionSet::RegisterEnumExtension(
                                    google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->containing_type()),
                                    extension->number(),
                                    extension->type(),
                                    extension->is_repeated(),
                                    extension->is_packed(),
                                    [](int){ return true; });
                                break;
                            case google::protobuf::internal::WireFormatLite::TYPE_MESSAGE:
                            case google::protobuf::internal::WireFormatLite::TYPE_GROUP:
                                google::protobuf::internal::ExtensionSet::RegisterMessageExtension(
                                    google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->containing_type()),
                                    extension->number(),
                                    extension->type(),
                                    extension->is_repeated(),
                                    extension->is_packed(),
                                    google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->extension_scope()));
                                break;
                            default:
                                google::protobuf::internal::ExtensionSet::RegisterExtension(
                                    google::protobuf::MessageFactory::generated_factory()->GetPrototype(extension->containing_type()),
                                    extension->number(),
                                    extension->type(),
                                    extension->is_repeated(),
                                    extension->is_packed());
                                break;
                        }
                    }

                    parsed.insert(fileName);
                    parsedSorted.push_back(fileName);
                }
            }
            else
                fprintf(stderr, "not parce %s\n", fileName.c_str());
        }
    }

    // and finally rebuild all protos in a new pool with fully resolved dependencies and extensions
    google::protobuf::DescriptorPool pool2;
    for (std::string const& fileName : parsedSorted)
    {
        std::ifstream in;
        in.open(fileName.c_str(), std::ios::binary | std::ios::in);
        if (!in.good())
            continue;

        google::protobuf::FileDescriptorProto fileDescProto;
        if (ParseFromIstreamWithDescriptorPool(fileDescProto, &in))
        {
            if (google::protobuf::FileDescriptor const* fileDesc = pool2.BuildFile(fileDescProto))
            {
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

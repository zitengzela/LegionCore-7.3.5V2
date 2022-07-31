/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Banner.h"
#include "GitRevision.h"
#include "StringFormat.h"

void Trinity::Banner::Show(char const* applicationName, void(*log)(char const* text), void(*logExtraInfo)())
{
    log(StringFormat("%s (%s)", GitRevision::GetFullVersion(), applicationName).c_str());
	log("<Ctrl-C> to stop.\n");
	log("       101010101010101100100101010                                                                                ");
	log("      10101010101010110010010101010                                                                               ");
	log("     00100                     01100                                                                              ");
	log("    10101   010101       0101   01010   01001                  10101                  01001                  10101");
	log("    10101   0101101      0101   01010   01001                  01010                  01001                  01010");
	log("    10101   01011010     0101   01010   10011        00        01010                  10011        00        01010");
	log("    10101   101010101    0101   01010   10101       1010       10101                  10101       1010       10101");
	log("    10101   0101010010   0101   01010   10010      011010      01010    010101010     01110      111001      01010");
	log("    10101   01011101101  1101   01010   01110     11110010     01010   01010110101    01110     11110010     01010");
	log("    10101   1010 0010011 0011   01010   01010    0001  0101    01010  101       101   01010    0001  0101    01010");
	log("    10101   0101  10010100101   01010   01001   1111    0100   10101  101       101   01001   1111    0100   10101");
	log("    10101   0101   0110110101   01010   01001  0110      1011  10101  101       101   01001  0110      1011  10101");
	log("    10101   0101    101100101   01010   10110 0100        1101 10101  101       101   10110 0100        1101 10101");
	log("    01010   1010     00100010   01010   101101011          011101010  101       101   101101011          011101010");
	log("    10101   1010      0100010   01010   10111000            01011101   01010110101    10111000            01011101");
	log("     0100                       0100    0011011              0011001    010101010     0011001              0011001");
	log("      10101010101010110010010101001                      ");
	log("       101010101010101100100101001                   ( C O R E---N O R D R A S S I L---P R O J E C T)             ");
	log("       ");
	log(" https://nordrassil.cubava.cu/                    \n");

    if (logExtraInfo)
        logExtraInfo();
}

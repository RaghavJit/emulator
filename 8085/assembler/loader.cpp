#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <regex>
using namespace std;

#include "loader.h"
#include "../components/memory.h"

namespace emu_8085 {

    const std::unordered_set<std::string> keywords = {
        "ACI",
        "ADC",
        "ADD",
        "ADI",
        "ANA",
        "ANI",
        "CALL",
        "CC",
        "CM",
        "CMA",
        "CMC",
        "CMP",
        "CNC",
        "CNZ",
        "CP",
        "CPE",
        "CPI",
        "CPO",
        "CZ",
        "DAA",
        "DAD",
        "DCR",
        "DCX",
        "DI",
        "EI",
        "HLT",
        "IN",
        "INR",
        "INX",
        "JC",
        "JM",
        "JMP",
        "JNC",
        "JNZ",
        "JP",
        "JPE",
        "JPO",
        "JZ",
        "LDA",
        "LDAX",
        "LHLD",
        "LXI",
        "MOV",
        "MVI",
        "NOP",
        "ORA",
        "ORI",
        "OUT",
        "PCHL",
        "POP",
        "PUSH",
        "RAL",
        "RAR",
        "RC",
        "RET",
        "RIM",
        "RLC",
        "RM",
        "RNC",
        "RNZ",
        "RP",
        "RPE",
        "RPO",
        "RRC",
        "RST",
        "RZ",
        "SBB",
        "SBI",
        "SHLD",
        "SIM",
        "SPHL",
        "STA",
        "STAX",
        "STC",
        "SUB",
        "SUI",
        "XCHG",
        "XRA",
        "XRI",
        "XTHL"
    };    
    
    const std::unordered_map<std::string, uint8_t> opcodes_1B = {
        {"ADC A", 0x8F}, {"ADC B", 0x88}, {"ADC C", 0x89}, {"ADC D", 0x8A},
        {"ADC E", 0x8B}, {"ADC H", 0x8C}, {"ADC L", 0x8D}, {"ADC M", 0x8E},

        {"ADD A", 0x87}, {"ADD B", 0x80}, {"ADD C", 0x81}, {"ADD D", 0x82},
        {"ADD E", 0x83}, {"ADD H", 0x84}, {"ADD L", 0x85}, {"ADD M", 0x86},

        {"ANA A", 0xA7}, {"ANA B", 0xA0}, {"ANA C", 0xA1}, {"ANA D", 0xA2},
        {"ANA E", 0xA3}, {"ANA H", 0xA4}, {"ANA L", 0xA5}, {"ANA M", 0xA6},

        {"CMA", 0x2F}, {"CMC", 0x3F},

        {"CMP A", 0xBF}, {"CMP B", 0xB8}, {"CMP C", 0xB9}, {"CMP D", 0xBA},
        {"CMP E", 0xBB}, {"CMP H", 0xBC}, {"CMP L", 0xBD}, {"CMP M", 0xBD},

        {"DAA", 0x27},

        {"DAD B", 0x09}, {"DAD D", 0x19}, {"DAD H", 0x29}, {"DAD SP", 0x39},

        {"DCR A", 0x3D}, {"DCR B", 0x05}, {"DCR C", 0x0D}, {"DCR D", 0x15},
        {"DCR E", 0x1D}, {"DCR H", 0x25}, {"DCR L", 0x2D}, {"DCR M", 0x35},

        {"DCX B", 0x0B}, {"DCX D", 0x1B}, {"DCX H", 0x2B}, {"DCX SP", 0x3B},

        {"DI", 0xF3}, {"EI", 0xFB}, {"HLT", 0x76},

        {"INR A", 0x3C}, {"INR B", 0x04}, {"INR C", 0x0C}, {"INR D", 0x14},
        {"INR E", 0x1C}, {"INR H", 0x24}, {"INR L", 0x2C}, {"INR M", 0x34},

        {"INX B", 0x03}, {"INX D", 0x13}, {"INX H", 0x23}, {"INX SP", 0x33},

        {"LDAX B", 0x0A}, {"LDAX D", 0x1A},

        {"MOV A A", 0x7F}, {"MOV A B", 0x78}, {"MOV A C", 0x79},
        {"MOV A D", 0x7A}, {"MOV A E", 0x7B}, {"MOV A H", 0x7C},
        {"MOV A L", 0x7D}, {"MOV A M", 0x7E},

        {"MOV B A", 0x47}, {"MOV B B", 0x40}, {"MOV B C", 0x41},
        {"MOV B D", 0x42}, {"MOV B E", 0x43}, {"MOV B H", 0x44},
        {"MOV B L", 0x45}, {"MOV B M", 0x46},

        {"MOV C A", 0x4F}, {"MOV C B", 0x48}, {"MOV C C", 0x49},
        {"MOV C D", 0x4A}, {"MOV C E", 0x4B}, {"MOV C H", 0x4C},
        {"MOV C L", 0x4D}, {"MOV C M", 0x4E},

        {"MOV D A", 0x57}, {"MOV D B", 0x50}, {"MOV D C", 0x51},
        {"MOV D D", 0x52}, {"MOV D E", 0x53}, {"MOV D H", 0x54},
        {"MOV D L", 0x55}, {"MOV D M", 0x56},

        {"MOV E A", 0x5F}, {"MOV E B", 0x58}, {"MOV E C", 0x59},
        {"MOV E D", 0x5A}, {"MOV E E", 0x5B}, {"MOV E H", 0x5C},
        {"MOV E L", 0x5D}, {"MOV E M", 0x5E},

        {"MOV H A", 0x67}, {"MOV H B", 0x60}, {"MOV H C", 0x61},
        {"MOV H D", 0x62}, {"MOV H E", 0x63}, {"MOV H H", 0x64},
        {"MOV H L", 0x65}, {"MOV H M", 0x66},

        {"MOV L A", 0x6F}, {"MOV L B", 0x68}, {"MOV L C", 0x69},
        {"MOV L D", 0x6A}, {"MOV L E", 0x6B}, {"MOV L H", 0x6C},
        {"MOV L L", 0x6D}, {"MOV L M", 0x6E},

        {"MOV M A", 0x77}, {"MOV M B", 0x70}, {"MOV M C", 0x71},
        {"MOV M D", 0x72}, {"MOV M E", 0x73}, {"MOV M H", 0x74},
        {"MOV M L", 0x75},

        {"NOP", 0x00},

        {"ORA A", 0xB7}, {"ORA B", 0xB0}, {"ORA C", 0xB1}, {"ORA D", 0xB2},
        {"ORA E", 0xB3}, {"ORA H", 0xB4}, {"ORA L", 0xB5}, {"ORA M", 0xB6},

        {"PCHL", 0xE9},

        {"POP B", 0xC1}, {"POP D", 0xD1}, {"POP H", 0xE1}, {"POP PSW", 0xF1},

        {"PUSH B", 0xC5}, {"PUSH D", 0xD5}, {"PUSH H", 0xE5}, {"PUSH PSW", 0xF5},

        {"RAL", 0x17}, {"RAR", 0x1F},

        {"RC", 0xD8}, {"RET", 0xC9}, {"RIM", 0x20},

        {"RLC", 0x07}, {"RM", 0xF8}, {"RNC", 0xD0}, {"RNZ", 0xC0},
        {"RP", 0xF0}, {"RPE", 0xE8}, {"RPO", 0xE0}, {"RRC", 0x0F},

        {"RST 0", 0xC7}, {"RST 1", 0xCF}, {"RST 2", 0xD7}, {"RST 3", 0xDF},
        {"RST 4", 0xE7}, {"RST 5", 0xEF}, {"RST 6", 0xF7}, {"RST 7", 0xFF},

        {"RZ", 0xC8},

        {"SBB A", 0x9F}, {"SBB B", 0x98}, {"SBB C", 0x99}, {"SBB D", 0x9A},
        {"SBB E", 0x9B}, {"SBB H", 0x9C}, {"SBB L", 0x9D}, {"SBB M", 0x9E},

        {"SIM", 0x30}, {"SPHL", 0xF9},

        {"STAX B", 0x02}, {"STAX D", 0x12}, {"STC", 0x37},

        {"SUB A", 0x97}, {"SUB B", 0x90}, {"SUB C", 0x91}, {"SUB D", 0x92},
        {"SUB E", 0x93}, {"SUB H", 0x94}, {"SUB L", 0x95}, {"SUB M", 0x96},

        {"XCHG", 0xEB},

        {"XRA A", 0xAF}, {"XRA B", 0xA8}, {"XRA C", 0xA9}, {"XRA D", 0xAA},
        {"XRA E", 0xAB}, {"XRA H", 0xAC}, {"XRA L", 0xAD}, {"XRA M", 0xAE},

        {"XTHL", 0xE3}
    }; 

    const std::unordered_map<std::string, uint8_t> opcodes_2B = {
        {"ACI", 0xCE},
        {"ADI", 0xC6},
        {"ANI", 0xE6},
        {"CPI", 0xFE},
        {"IN", 0xDB},

        {"MVI A", 0x3E},
        {"MVI B", 0x06},
        {"MVI C", 0x0E},
        {"MVI D", 0x16},
        {"MVI E", 0x1E},
        {"MVI H", 0x26},
        {"MVI L", 0x2E},
        {"MVI M", 0x36},

        {"ORI", 0xF6},
        {"OUT", 0xD3},
        {"SBI", 0xDE},
        {"SUI", 0xD6},
        {"XRI", 0xEE}
    };

    const std::unordered_map<std::string, uint8_t> opcodes_3B = {
        {"CALL", 0xCD},
        {"CC",   0xDC},
        {"CM",   0xFC},
        {"CNC",  0xD4},
        {"CNZ",  0xC4},
        {"CP",   0xF4},
        {"CPE",  0xEC},
        {"CPO",  0xE4},
        {"CZ",   0xCC},

        {"JC",   0xDA},
        {"JM",   0xFA},
        {"JMP",  0xC3},
        {"JNC",  0xD2},
        {"JNZ",  0xC2},
        {"JP",   0xF2},
        {"JPE",  0xEA},
        {"JPO",  0xE2},
        {"JZ",   0xCA},

        {"LDA",  0x3A},
        {"LHLD", 0x2A},

        {"LXI BC",  0x01},
        {"LXI DE",  0x11},
        {"LXI HL",  0x21},
        {"LXI SP", 0x31},

        {"SHLD", 0x22},
        {"STA",  0x32}
    };

    std::unordered_map<std::string, uint16_t> label_addresses = {};

    bool isLabel(std::string str) {
        std::regex pattern("[a-zA-Z]+[a-zA-Z0-9]*:");
        return std::regex_match(str, pattern);
    }

    bool isLabelCall(std::string str) {
        return (label_addresses.count(str) > 0);
    }

    bool isHex(std::string str) {
        std::regex pattern("[0-9A-Fa-f]{2,4}[Hh]");
        return std::regex_match(str, pattern);
    }

    std::string joinInst(std::vector<std::string> instruction){
        std::string result;

        for (size_t i = 0; i < instruction.size() - 1; ++i) {
            if (isLabel(instruction[i])) {
                continue;
            }
            result += instruction[i];
            if (i != instruction.size() - 2) 
                result += " ";
        }
        return result;
    }

    uint16_t stringToUint16(std::string str) {
        if (str.size() != 4) {
            return UINT16_MAX; 
        }
        std::stringstream ss;
        uint16_t value = 0;
        ss << std::hex << str;
        ss >> value;

        return value;
    }

    std::vector<std::string> tokenize(const char* filepath) {
        std::vector<std::string> token_list;
        std::ifstream asm_file(filepath);

        if (!asm_file.is_open()) {
            return token_list; 
        }

        std::string current;
        bool in_comment = false;
        char c;

        while(asm_file.get(c)) {
            if (in_comment) {
                if (c == '\n' || c == '\r') {
                    in_comment = false;
                }
                continue;
            }
            if (c == ';') {
                if (!current.empty()) {
                    token_list.push_back(current);
                    current = "";
                }
                in_comment = true;
                continue;
            }
            if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
                if (!current.empty()) {
                    token_list.push_back(current);
                    current = "";
                }
                continue;
            }
            if (std::isalnum(static_cast<unsigned char>(c)) || c == ':') {
                current += c;
                continue;
            }
        }

        if (!current.empty()) {
            token_list.push_back(current);
        }

        return token_list;
    }

    std::vector<std::vector<std::string>> format(std::vector<std::string> token_list) {
        std::vector<std::vector<std::string>> modified_token_list = {};
        std::vector<std::string> instruction = {};

        for (size_t i=0; i<token_list.size(); i++) {
            if (isLabel(token_list[i])) {
                if (!instruction.empty()) {
                    modified_token_list.push_back(instruction);
                    instruction.clear();
                }
                instruction.push_back(token_list[i]);
                label_addresses.insert({instruction[0], modified_token_list.size()});
                if (i + 1 < token_list.size()) {
                    instruction.push_back(token_list[++i]);
                }
                continue;
            }
            else if (keywords.count(token_list[i])) {
                if (!instruction.empty()) {
                    modified_token_list.push_back(instruction);
                    instruction.clear();
                }
            }
            instruction.push_back(token_list[i]);
        }
        modified_token_list.push_back(instruction);

        return modified_token_list;
    }

    bool loadASM(const char* filepath, const char* address) {
        int prog_size_tracker = 0;
        std::vector<std::string> token_list = tokenize(filepath);
        std::vector<std::vector<std::string>> modified_token_list = format(token_list);
        
        emu_8085::Memory pre_exec_memory;
        uint8_t pointer = stringToUint16(address);

        for(auto& row : modified_token_list) {
            std::string match = joinInst(row);
            std::cout<<match<<" "<<row.back()<<std::endl;
            if (auto it = opcodes_1B.find(match + " " +row.back()); it!=opcodes_1B.end()) {
                pointer = pre_exec_memory.saveToLocation(it->second, pointer);
                continue;
            }
            else if (auto it = opcodes_2B.find(match); it!=opcodes_2B.end()) {
                pointer = pre_exec_memory.saveToLocation(it->second, pointer);
            }
            else if (auto it = opcodes_3B.find(match); it!=opcodes_3B.end()) {
                pointer = pre_exec_memory.saveToLocation(it->second, pointer);
            }

            if (isHex(row.back())) {
                if (row.back().size() == 3) {
                    pointer = pre_exec_memory.saveToLocation((uint8_t)(stringToUint16(row.back()) >> 8), pointer);
                std::cout<<"2hex:"<<row.back()<<std::endl;
                }
                else {
                    pointer = pre_exec_memory.saveToLocation(stringToUint16(row.back()), pointer);
                std::cout<<"4hex: "<<row.back()<<std::endl;
                }
            }
            else if (isLabelCall(row.back()+":")) {
                std::cout<<"labelCall: "<<label_addresses[row.back()+":"]+stringToUint16(address)<<std::endl;
                //std::cout<<row.back()<<" "<<label_addresses[row.back()]<<endl;
//                pointer = pre_exec_memory.saveToLocation(stringToUint16(label_addresses[row.back()] + stringToUint16(address)), pointer);
            }
        }
//        pre_exec_memory.viewMemory(stringToUint16(address));
//        pre_exec_memory.saveMemory("output.dat");
        return true;
    }


}       


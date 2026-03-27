#include <cstdint>
#include <array>
#include <fstream>
#include <iostream>

#include "memory.h"

namespace emu_8085 {


    Memory::Memory(const char* path){
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            std::cout<<"Error: Failed to open saved memory snapshot!"<<std::endl;
            return;
        }

        file.read(reinterpret_cast<char*>(mem.data()), mem.size());

        if (!file) {
            std::cout << "Error: Memory incomplete!";
        }
    }

    void Memory::clearMemory() {
        mem.fill(0x00);
        return;
    }
    
    uint16_t Memory::saveToLocation(uint8_t data, uint16_t address){
        if (address >= mem.size()) {
            return address;
        }
        mem[address] = data;
        return address + 1;
    }

    uint8_t Memory::getFromLocation(uint16_t address) {
        if (address >= mem.size()) {
            return 0x00;
        }
        return mem[address];
    }

    void Memory::saveMemory(const char* path) {
        std::ofstream file(path, std::ios::binary);
        if (!file.is_open()) {
            std::cout<< "Error: Failed to open file for writing!"<<std::endl;
            return;
        }
        file.write(reinterpret_cast<const char*>(mem.data()), mem.size());
        file.close(); 
        return;
    }
}       


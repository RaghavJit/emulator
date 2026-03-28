#include <cstdint>
#include <array>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "memory.h"

namespace emu_8085 {


    Memory::Memory() {
        mem.fill(0x00);  
    }

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

    uint16_t Memory::saveToLocation(uint16_t data, uint16_t address){
        if (address+1 >= mem.size()) {
            return address;
        }
        mem[address] = (data >> 8) & 0xFF;
        mem[address+1] = data & 0xFF;
        return address + 2;
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

    void Memory::viewMemory(uint16_t address) {
        for (uint16_t i = 0; i < 100; i++) {
            uint16_t value = mem[address + i];

            std::cout << "0x"
                      << std::hex << std::setw(2) << std::setfill('0')
                      << std::uppercase
                      << static_cast<int>(value & 0xFF)   // print only 1 byte
                      << " ";

            std::cout << std::dec;  // reset formatting
        }
    }
}       


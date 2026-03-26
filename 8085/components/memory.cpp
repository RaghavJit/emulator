#include <cstdint>
#include <array>
#include <fstream>

#include "memory.h"

namespace emu_8085 {


    Memory::Memory(cost char* path){
        ofstream file(path, ios::binary);
        if (!file.is_open()) {
            cerr
                << "Error: Failed to open file for writing."
                << endl;
            return;
        }
        file.write(reinterpret_cast<const char*>(this),
                   sizeof(*this));
        file.close();
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
}       


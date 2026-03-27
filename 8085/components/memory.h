#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>
#include <array>

namespace emu_8085 {


    class Memory {
        
        friend class Bus;

        private:
            std::array<uint8_t, 65536> mem {};
        
        public:
            Memory();
            Memory(const char* path);
            void clearMemory();
            uint16_t saveToLocation(uint8_t data, uint16_t address);
            uint16_t saveToLocation(uint16_t data, uint16_t address);
            uint8_t getFromLocation(uint16_t address);
            void saveMemory(const char* path);
            void viewMemory(uint16_t address);
    };
    

}

#endif


#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>
#include <array>

namespace emu_8085 {


    class Memory {
        
        friend class Bus;

        private:
            std::array<uint8_t, 65536> memory {};
        
        public:
            void clearMemory();
            void saveMemory();
            void loadMemory();
    };
    

}

#endif


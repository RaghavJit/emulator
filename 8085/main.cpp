#include "utils.h"
#include "parser.h"
#include "emulator_8085.h"

int main(int argc, char* argv[]){
    
    if(argc > 2) {
        std::cout <<"Error: More than one args were provided!"<<std::endl;
    }
    
    if (!std::filesystem::exists(argv[1])) {
        std::cout << "Error: File does NOT exist!"<<std::endl;
    }

    std::cout<<"Parsing the file"<<std::endl;
    if (emu_8085::parseASM(argv[1])) {
        std::cout<<"Syntax valid executing the instructions"<<std::endl;

        emu_8085::address start_address = emu_8085::loadASMToMemory(argv[1])
        emu_8085::exec(start_address)
    }
    
    return 0;
}

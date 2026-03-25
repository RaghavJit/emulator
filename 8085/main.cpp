#include "utils.h"
#include "assembler.h"
#include "components.h"

int main(int argc, char* argv[]){
    
    if(argc > 2) {
        std::cout <<"Error: More than one args were provided!"<<std::endl;
        return 1;
    }
    
    if (!std::filesystem::exists(argv[1])) {
        std::cout << "Error: File does not exist!"<<std::endl;
        return 1;
    }

    std::cout<<"Parsing the file"<<std::endl;
    if (!emu_8085::parseASM(argv[1])) {
        std::cout<<"Error: Syntax error!"<<std::endl;
        return 1;
    }

    std::cout<<"Loading ASM into memory"<<std::endl;
    if (!emu_8085::loadASM(argv[1])) {
        std::cout<<"Error: Could not load ASM to memory!"<<std::endl;
        return 1;
    }

    std::cout<<"Executing instructions"<<std::endl;
    if (!emu_8085::execASM(argv[1])) {
        std::cout<<"Error: Problem occured during execution!"<<std::endl;
        return 1;
    }
    
    return 0;
}

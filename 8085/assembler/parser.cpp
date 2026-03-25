#include <fstream>
using namespace std;

#include "parser.h"

extern FILE* yyin;
extern int yyparse();

namespace emu_8085 {
    bool parseASM(const char* filepath) {
        yyin = fopen(filepath, "r");
        if (!yyin) return false;

        int result = yyparse();
        fclose(yyin);

        return result == 0;
    }
}

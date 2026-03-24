#include <iostream>

extern FILE* yyin;
int yyparse();

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Usage: ./parser <file>\n";
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cout << "Cannot open file\n";
        return 1;
    }

    if (yyparse() == 0) {
        std::cout << "Valid string\n";
    } else {
        std::cout << "Invalid string\n";
    }

    return 0;
}


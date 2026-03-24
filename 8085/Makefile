EMU_LIB_SOURCES := $(wildcard ./emulator_8085/*.cpp)
EMU_LIB_OBJECTS := $(patsubst ./emulator_8085/%.cpp, ./emu_objs/%.o, $(EMU_LIB_SOURCES))

PARS_LIB_SOURCES := $(wildcard ./loader/*.cpp)
PARS_LIB_OBJECTS := $(patsubst ./loader/%.cpp, ./pars_objs/%.o, $(PARS_LIB_SOURCES))

CPPFLAGS = -Wall -Wextra

all: emulator

emulator: $(EMU_LIB_OBJECTS) $(PARS_LIB_OBJECTS) ./pars_objs/parser.tab.o ./pars_objs/lex.yy.o main.o
	g++ $(CPPFLAGS) $^ -o $@

main.o: main.cpp
	g++ $(CPPFLAGS) -c $^

./emu_objs/%.o: ./emulator_8085/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@

./pars_objs/%.o: ./loader/%.cpp
	g++ $(CPPFLAGS) -I./loader -c $< -o $@

./pars_objs/parser.tab.o: ./loader/parser.tab.c
	g++ $(CPPFLAGS) -I./loader -c $< -o $@

./pars_objs/lex.yy.o: ./loader/lex.yy.c
	g++ $(CPPFLAGS) -I./loader -c $< -o $@

parser:
	bison -d -o ./loader/parser.tab.c ./loader/parser.y
	flex  -o ./loader/lex.yy.c ./loader/lexer.l

clean:
	rm -f emulator *.o ./emu_objs/* ./pars_objs/* ./loader/*.tab.* ./loader/lex.yy.c

COMPONENTS_SOURCES := $(wildcard ./components/*.cpp)
COMPONENTS_OBJECTS := $(patsubst ./components/%.cpp, ./comp_objs/%.o, $(COMPONENTS_SOURCES))

ASMB_SOURCES := $(wildcard ./assembler/*.cpp)
ASMB_OBJECTS := $(patsubst ./assembler/%.cpp, ./asmb_objs/%.o, $(ASMB_SOURCES))

CPPFLAGS = -Wall -Wextra

all: emulator

emulator: $(COMPONENTS_OBJECTS) $(ASMB_OBJECTS) ./asmb_objs/parser.tab.o ./asmb_objs/lex.yy.o main.o
	g++ $(CPPFLAGS) $^ -o $@

main.o: main.cpp
	g++ $(CPPFLAGS) -c $^

./comp_objs/%.o: ./components/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@

./asmb_objs/%.o: ./assembler/%.cpp
	g++ $(CPPFLAGS) -I./assembler -c $< -o $@

./asmb_objs/parser.tab.o: ./assembler/parser.tab.c
	g++ $(CPPFLAGS) -I./assembler -c $< -o $@

./asmb_objs/lex.yy.o: ./assembler/lex.yy.c
	g++ $(CPPFLAGS) -I./assembler -c $< -o $@

parser:
	bison -d -o ./assembler/parser.tab.c ./assembler/parser.y
	flex  -o ./assembler/lex.yy.c ./assembler/lexer.l

clean:
	rm -f emulator *.o ./comp_objs/* ./asmb_objs/* ./assembler/*.tab.* ./assembler/lex.yy.c

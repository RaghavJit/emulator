LIB_SOURCES := $(wildcard ./emulator_8085/*.cpp)
LIB_OBJECTS := $(patsubst ./emulator_8085/%.cpp, ./objs/%.o, $(LIB_SOURCES))

CPPFLAGS = -Wall -Wextra

all:emulator

emulator: $(LIB_OBJECTS) main.o 
	g++ $(CPPFLAGS) $^ -o $@

main.o: main.cpp
	g++ $(CPPFLAGS) -c $^

./objs/%.o: ./emulator_8085/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm ./emulator ./objs/* ./*.exe *.o


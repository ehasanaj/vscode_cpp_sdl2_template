CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN := bin
SRC	:= src/*.cpp \
	src/utils/*.cpp
	
INCLUDE := -Iinclude \
	-Iinclude/utils \
	-Ilib/SDL2/2.0.12_1/include/SDL2 \
	-Ilib/SDL2_IMAGE/2.0.5/include/SDL2

LIBRARIES   := -Llib/SDL2/2.0.12_1/lib -lSDL2 \
	-Llib/SDL2_IMAGE/2.0.5/lib -lSDL2_image

EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) $(INCLUDE) $(LIBRARIES) $^ -o $@

clean:
	-rm $(BIN)/*
CXX = g++

CXXFLAGS = -Wall -std=c++11

ODIR = obj
SDIR = src
INC = -Iinc -lGL -lsfml-graphics -lsfml-window -lsfml-system
OUT = PuzzleFight

OBJS = main.o Game.o BehaviourObject.o RenderObject.o Utils.o Input.o Box.o Board.o FallingBox.o

.PHONY: all clean

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJS) $(INC)

clean:
	rm *.o $(OUT)

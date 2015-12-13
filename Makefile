AVATAR := avatar

CC := g++
CFLAGS := -w -std=c++11
LFLAGS := -lSDL2 -lSDL2_image -lGL -lGLU -lGLEW 
INCLUDE := include
SOURCE := src
BUILD := build

CPPFILES := $(foreach dir, $(SOURCE)/, $(notdir $(wildcard $(SOURCE)/*.cpp)))
OBJFILES := $(addprefix $(BUILD)/, $(CPPFILES:.cpp=.o))
DEPFILES := $(addprefix $(INCLUDE)/, $(CPPFILES:.cpp=.hpp))

all: $(AVATAR)

$(AVATAR): $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o $(AVATAR) $(LFLAGS) 

$(BUILD)/%.o: $(SOURCE)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ 


.PHONY: clean

clean:
	rm -f $(BUILD)/*.o
	rm -f $(AVATAR)

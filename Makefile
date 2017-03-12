AVATAR := avatar

VULKAN_SDK_PATH := /home/avatar/dev/VulkanSDK/1.0.42.0/x86_64

CC := g++
CFLAGS := -w -std=c++11 -I$(VULKAN_SDK_PATH)/include -DNDEBUG=1
LFLAGS := -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan 
INCLUDE := include
SOURCE := src
BUILD := build
SHADERS := shaders

CPPFILES := $(foreach dir, $(SOURCE)/, $(notdir $(wildcard $(SOURCE)/*.cpp)))
OBJFILES := $(addprefix $(BUILD)/, $(CPPFILES:.cpp=.o))
DEPFILES := $(addprefix $(INCLUDE)/, $(CPPFILES:.cpp=.hpp))

all: $(AVATAR)
	./src/shaders/compile.sh

$(AVATAR): $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o $(AVATAR) $(LFLAGS) 

$(BUILD)/%.o: $(SOURCE)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ 

test: $(AVATAR)
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/explicit_layer.d ./avatar
	
clean:
	mkdir -p $(BUILD)
	mkdir -p $(SHADERS)
	rm -f $(BUILD)/*.o
	rm -rf $(SHADERS)/*.vert
	rm -f $(AVATAR)

.PHONY: clean

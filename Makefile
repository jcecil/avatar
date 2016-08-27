AVATAR := avatar

VULKAN_SDK_PATH := /home/avatar/projects/VulkanSDK/1.0.21.1/x86_64

CC := g++
CFLAGS := -w -std=c++11 -I$(VULKAN_SDK_PATH)/include
LFLAGS := -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan 
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
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ 

test: $(AVATAR)
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/explicit_layer.d ./avatar
	
clean:
	rm -f $(BUILD)/*.o
	rm -f $(AVATAR)

.PHONY: clean

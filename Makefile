#File Directory things (might be overkill idk yet)
# INCLUDE = -I$(SRC_DIR)/headers
OBJ_NAME = Invaders

BUILD_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

#Compiler and linker things
CC = gcc
CCFLAGS = `sdl2-config --libs --cflags`
CCFLAGS += -g
# SDL = -lSDL2main -lSDL2 #-lSDL_image -lSDL_ttf
LD = ld
LDFLAGS = 
INCLUDES = -Isrc/headers

SRC = $(call rwildcard,$(SRC_DIR),*.c) 
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJS += $(patsubst $(SRC_DIR)/%.asm, $(OBJ_DIR)/%_asm.o, $(ASMSRC))
DIRS = $(wildcard $(SRC_DIR)/*)

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

#Essential files and groups

all: Emulator
Emulator: $(BUILD_DIR)/$(OBJ_NAME)

$(BUILD_DIR)/$(OBJ_NAME): $(OBJS)
	@ echo ~~~~~ LINKING $^ ~~~~~
	@ mkdir -p $(@D)
	$(CC) -o $@ $^ $(CCFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ echo ~~~~~ COMPILING $^ ~~~~~
	@ mkdir -p $(@D)
	$(CC) -c -o $@ $(INCLUDES) $< $(CCFLAGS)

setup:
	@mkdir $(OBJ_DIR)
	@mkdir $(BUILD_DIR)

clean:
	rm -rf $(OBJ_DIR)/
	rm -rf $(BUILD_DIR)/
	rm ROM/invaders
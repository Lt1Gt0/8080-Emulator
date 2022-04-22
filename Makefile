#File Directory things (might be overkill idk yet)
# INCLUDE = -I$(SRC_DIR)/headers
OBJ_NAME = Emulator

BUILD_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

#Compiler and linker things
CC = gcc
CCFLAGS = -g#-g -Wall -Wextra
CCFLAGS +=
LD = ld
LDFLAGS = 

SRC = $(call rwildcard,$(SRC_DIR),*.c) 
ASMSRC = $(call rwildcard,$(SRC_DIR),*.asm) 
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
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ echo ~~~~~ COMPILING $^ ~~~~~
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR)/%_asm.o: $(SRC_DIR)/%.asm
	@ echo ~~~~~ COMPILING $^ ~~~~~
	@ mkdir -p $(@D)
	$(ASMC) $(ASMFLAGS) $^ -f elf64 -o $@

link: 
	@ echo ~~~~~ LINKING ~~~~~
	$(CC) $(CCFLAGS) 
	
# $(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

setup:
	@mkdir $(OBJ_DIR)
	@mkdir $(BUILD_DIR)

clean:
	rm -rf $(OBJ_DIR)/
	rm -rf $(BUILD_DIR)/
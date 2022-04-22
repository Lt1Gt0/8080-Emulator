#File Directory things (might be overkill idk yet)
# INCLUDE = -I$(SRC_DIR)/headers
DISASSEMBLER_OBJNAME = Disassembler
INVADERS_OBJNAME = Invaders
8080_OBJNAME = 8080


BUILD_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

DISASSEMBLER_SRC_DIR = $(SRC_DIR)/$(DISASSEMBLER_OBJNAME)
DISASSEMBLER_OBJ_DIR = $(OBJ_DIR)/$(DISASSEMBLER_OBJNAME)

8080_SRC_DIR = $(SRC_DIR)
8080_OBJ_DIR = $(OBJ_DIR)

# INVADERS_SRC = $(SRC_DIR)/$(INVADERS_OBJNAME)
# INVADERS_OBJ_DIR = $(SRC_DIR)/$(INVADERS_OBJNAME)

#Compiler and linker things
CC = gcc
CCFLAGS = -g#-g -Wall -Wextra
CCFLAGS +=
LD = ld
LDFLAGS = 

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

#Essential files and groups

DISASSEMBLER_SRCS = $(call rwildcard, $(DISASSEMBLER_SRC_DIR), *.c)
DISASSEMBLER_ASMSRCS = $(call rwildcard, $(DISASSEMBLER_SRC_DIR), *.asm)
DISASSEMBLER_OBJ = $(addprefix $(BUILD_DIR)/, $(DISASSEMBLER_OBJNAME))
DISASSEMBLER_OBJS = $(patsubst $(DISASSEMBLER_SRC)/%.c, $(DISASSEMBLER_OBJ_DIR)/%.o, $(DISASSEMBLER_SRCS))


8080_SRCS = $(call rwildcard, $(8080_SRC_DIR), *.c)
8080_ASMSRCS = $(call rwildcard, $(8080_SRC_DIR), *.asm)
8080_OBJ = $(addprefix $(BUILD_DIR)/, $(8080_OBJNAME))
8080_OBJS = $(patsubst $(8080_SRC)/%.c, $(8080_OBJ_DIR)/%.o, $(8080_SRCS))

all: setup disassembler 8080
	@echo ---- GENERATING $^ ----

disassembler: setup $(DISASSEMBLER_OBJ)

$(DISASSEMBLER_OBJ): $(DISASSEMBLER_OBJS)
	@echo ---- LINKING $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $^ -o $@

$(DISASSEMBLER_OBJ_DIR)/%.o: $(DISASSEMBLER_SRC_DIR)/%.c
	@echo ---- COMPILING $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c $< -o $@

8080: setup $(8080_OBJ)

$(8080_OBJ): $(8080_OBJS)
	@echo ---- LINKING $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $^ -o $@

$(8080_OBJ_DIR)/%.o: $(8080_SRC_DIR)/%.c
	@echo ---- COMPILING $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c $< -o $@

	
# $(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

setup:
	@mkdir $(OBJ_DIR)
	@mkdir $(DISASSEMBLER_OBJ_DIR)
# @mkdir $(INVADERS_OBJ_DIR)
	@mkdir $(BUILD_DIR)

clean:
	rm -rf $(OBJ_DIR)/
	rm -rf $(BUILD_DIR)/
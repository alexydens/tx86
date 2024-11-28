SRC_DIR=src
INC_DIR=include
CONF_DIR=conf

OBJ_DIR=obj
BIN_DIR=bin
ISO_DIR=iso

CC=clang -target x86_64-unknown-none
AS=clang -target x86_64-unknown-none
LD=ld.lld

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
CFLAGS += -nostdinc
CFLAGS += -O0
CFLAGS += -ffreestanding -fno-PIC -fno-lto
CFLAGS += -fno-stack-check -fno-stack-protector
CFLAGS += -I$(INC_DIR)
CFLAGS += -mcmodel=kernel -mno-red-zone

LDFLAGS = -nostdlib -static -z max-page-size=0x1000
LDFLAGS += -O0
LDFLAGS += -T $(CONF_DIR)/linker.ld
LDFLAGS += -m elf_x86_64

C_SOURCES = $(wildcard $(SRC_DIR)/*.c)
ASM_SOURCES = $(wildcard $(SRC_DIR)/*.S)

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SOURCES))
OBJECTS += $(patsubst $(SRC_DIR)/%.S, $(OBJ_DIR)/%.o, $(ASM_SOURCES))

$(OBJ_DIR):
	mkdir -p $@
$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "\tCC\t$<\n"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.S | $(OBJ_DIR)
	@printf "\tCC\t$<\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/kernel.elf: $(OBJECTS) | $(BIN_DIR)
	@printf "\tLD\n"
	@for obj in $(OBJECTS) ; do \
		printf "\t\t$$obj\n" ; \
	done
	@$(LD) $(LDFLAGS) $(OBJECTS) -o $@

$(BIN_DIR)/kernel.iso: $(BIN_DIR)/kernel.elf
	mkdir -p $(ISO_DIR)/boot/grub
	cp $(CONF_DIR)/grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	cp $(BIN_DIR)/kernel.elf $(ISO_DIR)/boot/kernel.elf
	grub-mkrescue -o $@ $(ISO_DIR)

.PHONY: clean build test

build: $(BIN_DIR)/kernel.iso

test: build
	qemu-system-x86_64 \
		-cdrom $(BIN_DIR)/kernel.iso \
		-serial mon:stdio \
		-nographic

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(ISO_DIR)

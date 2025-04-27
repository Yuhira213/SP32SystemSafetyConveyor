# Compiler dan Flags
CC = gcc
CFLAGS = -I./unity -I. -I/path/to/STM32Cube/STM32Cube_FW_F4_V1.x.x/Drivers/STM32F4xx_HAL_Driver/Inc  # Menambahkan path ke STM32 HAL
LDFLAGS = -lm

# Sumber file
SRC = test_load_cell.c unity/unity.c load_cell.c
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = test_load_cell

# Aturan default
all: $(TARGET)

# Mengompilasi dan membuat executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Menjalankan unit test
run: $(TARGET)
	./$(TARGET)

# Membersihkan file yang sudah dibangun
clean:
	rm -f $(OBJ) $(TARGET)

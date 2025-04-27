# Compiler dan Flags
CC = gcc
CFLAGS = -I./unity -I.  # Menyertakan direktori Unity dan proyek
LDFLAGS = -lm

# Sumber file
SRC = test_buzzer.c unity/unity.c buzzer.c
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = test_buzzer

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

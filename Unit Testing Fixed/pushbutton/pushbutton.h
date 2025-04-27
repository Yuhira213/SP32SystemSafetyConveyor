#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <stdint.h>

// Fungsi untuk menginisialisasi tombol
void PushButton_Init(void);

// Fungsi untuk membaca status tombol
uint8_t PushButton_Read(void);

// Fungsi untuk mengontrol status tombol (virtual tanpa GPIO)
void PushButton_Control(uint8_t state);

#endif // PUSHBUTTON_H

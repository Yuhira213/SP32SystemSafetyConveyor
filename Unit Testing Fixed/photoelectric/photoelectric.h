#include <stdint.h>

#ifndef PHOTOELECTRIC_H
#define PHOTOELECTRIC_H

// Fungsi untuk menginisialisasi sensor photoelectric
void Photoelectric_Init(void);

// Fungsi untuk membaca status sensor photoelectric (terhalang / tidak terhalang)
uint8_t Photoelectric_Read(void);

// Fungsi untuk mengubah status sensor secara manual (untuk simulasi/testing)
void Photoelectric_SetStatus(int status);

#endif // PHOTOELECTRIC_H

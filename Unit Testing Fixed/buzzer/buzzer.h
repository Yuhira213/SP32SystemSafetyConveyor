#ifndef BUZZER_H
#define BUZZER_H

#include <stdint.h>

// Fungsi untuk menginisialisasi buzzer
void Buzzer_Init(void);

// Fungsi untuk mengontrol buzzer
void Buzzer_Control(uint8_t state);

// Fungsi untuk membaca status buzzer
uint8_t Buzzer_GetStatus(void);

#endif // BUZZER_H

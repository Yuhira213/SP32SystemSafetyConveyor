#ifndef RELAY_H
#define RELAY_H

#include <stdint.h>

// Status relay (0 = OFF, 1 = ON)
extern uint8_t relay_status;  // Variabel untuk menyimpan status relay

// Fungsi untuk menginisialisasi relay
void Relay_Init(void);

// Fungsi untuk mengontrol relay
void Relay_Control(uint8_t state);

// Fungsi untuk mendapatkan status relay
uint8_t Relay_GetStatus(void);

#endif // RELAY_H

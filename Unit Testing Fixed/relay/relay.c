#include "relay.h"
#include <stdio.h>

// Status relay (0 = OFF, 1 = ON)
uint8_t relay_status = 0;  // Defaultnya relay dalam keadaan OFF

// Fungsi untuk menginisialisasi relay
void Relay_Init(void) {
    relay_status = 0;  // Set relay awal dalam keadaan OFF
    printf("Relay Initialized. Status: OFF\n");
}

// Fungsi untuk mengontrol relay
void Relay_Control(uint8_t state) {
    if (state != 0U) {
        relay_status = 1;  // Relay ON
        printf("Relay is ON\n");
    } else {
        relay_status = 0;  // Relay OFF
        printf("Relay is OFF\n");
    }
}

// Fungsi untuk mendapatkan status relay
uint8_t Relay_GetStatus(void) {
    return relay_status;
}

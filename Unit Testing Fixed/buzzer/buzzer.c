#include "buzzer.h"
#include <stdio.h>

// Status buzzer (0 = mati, 1 = hidup)
static uint8_t buzzer_status = 0;  // Buzzer dimulai dalam keadaan mati

// Fungsi untuk menginisialisasi buzzer
void Buzzer_Init(void) {
    buzzer_status = 0;  // Set buzzer awal dalam keadaan mati
    printf("Buzzer Inisialisasi. Status: Mati\n");
}

// Fungsi untuk mengontrol buzzer (mengubah status)
void Buzzer_Control(uint8_t state) {
    if (state != 0U) {
        buzzer_status = 1;  // Buzzer hidup
        printf("Buzzer Dihidupkan\n");
    } else {
        buzzer_status = 0;  // Buzzer mati
        printf("Buzzer Dimatikan\n");
    }
}

// Fungsi untuk mendapatkan status buzzer (untuk pengujian)
uint8_t Buzzer_GetStatus(void) {
    return buzzer_status;  // Mengembalikan status buzzer
}

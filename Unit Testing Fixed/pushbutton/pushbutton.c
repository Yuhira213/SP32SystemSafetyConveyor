#include "pushbutton.h"
#include <stdio.h>

// Status tombol (0 = tidak ditekan, 1 = ditekan)
static uint8_t button_status = 0;  // Tombol dimulai dalam keadaan tidak ditekan

// Fungsi untuk menginisialisasi tombol
void PushButton_Init(void) {
    button_status = 0;  // Set tombol awal dalam keadaan tidak ditekan
    printf("Tombol Inisialisasi. Status: Tidak Ditekan\n");
}

// Fungsi untuk mengontrol status tombol (virtual, tanpa GPIO)
void PushButton_Control(uint8_t state) {
    if (state != 0U) {
        button_status = 1;  // Tombol ditekan
        printf("Tombol Ditekan (Aktif)\n");
    } else {
        button_status = 0;  // Tombol tidak ditekan
        printf("Tombol Tidak Ditekan\n");
    }
}

// Fungsi untuk membaca status tombol
uint8_t PushButton_Read(void) {
    return button_status;  // Mengembalikan status tombol
}

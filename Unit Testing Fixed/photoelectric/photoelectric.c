#include "photoelectric.h"

// Variabel untuk menyimpan status sensor (0 = tidak terhalang, 1 = terhalang)
static int sensor_status = 0;  // Defaultnya sensor tidak terhalang (0)

// Fungsi untuk menginisialisasi sensor
void Photoelectric_Init(void) {
    // Simulasi inisialisasi sensor
    sensor_status = 0;  // Setel status sensor ke "tidak terhalang"
}

// Fungsi untuk membaca status sensor (terhalang / tidak terhalang)
uint8_t Photoelectric_Read(void) {
    // Kembalikan status sensor
    return (uint8_t)sensor_status;
}

// Fungsi untuk mengubah status sensor secara manual (untuk simulasi/testing)
void Photoelectric_SetStatus(int status) {
    if (status == 0 || status == 1) {
        sensor_status = status;  // 0 = tidak terhalang, 1 = terhalang
    }
}

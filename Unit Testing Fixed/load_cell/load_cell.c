#include "load_cell.h"
#include <stdio.h>
#include <stdlib.h> // Untuk rand() dan srand()
#include <time.h>   // Untuk time() untuk menginisialisasi rand()

// Variabel global untuk simulasi perubahan berat
static float load_cell_weight = 1000.0f;  // Nilai awal 1000 gram

/* Fungsi untuk membaca nilai dari Load Cell (simulasi tanpa ADC) */
float read_load_cell(void)
{
    // Setiap kali fungsi dipanggil, berat akan berubah secara acak dalam rentang tertentu
    // Misalnya, berat akan berubah dengan acak antara -10 hingga +10 gram
    load_cell_weight += (rand() % 21 - 10);  // Mengubah nilai antara -10 hingga +10 gram
    
    // Pastikan nilai tidak keluar dari rentang yang masuk akal
    if (load_cell_weight < 950.0f) {
        load_cell_weight = 950.0f;  // Batas bawah (950 gram)
    }
    if (load_cell_weight > 1050.0f) {
        load_cell_weight = 1050.0f;  // Batas atas (1050 gram)
    }

    return load_cell_weight;
}

/* Fungsi utama dengan logika while untuk memonitor berat load cell */
void monitor_load_cell_weight(void) {
    float current_weight = 0.0f;
    float lower_limit = 950.0f;  // Batas bawah berat (gram)
    float upper_limit = 1050.0f; // Batas atas berat (gram)
    
    int iteration_count = 0;  // Counter untuk iterasi

    while (iteration_count < 5) {  // Hanya jalankan 5 iterasi
        // Baca berat dari load cell (menggunakan simulasi)
        current_weight = read_load_cell();

        // Periksa apakah berat di luar rentang yang diinginkan
        if (current_weight < lower_limit) {
            // Tindakan jika berat kurang dari 950 gram
            printf("Warning: Weight below lower limit! Current weight: %.2f grams\n", current_weight);
        } 
        else if (current_weight > upper_limit) {
            // Tindakan jika berat lebih dari 1050 gram
            printf("Warning: Weight above upper limit! Current weight: %.2f grams\n", current_weight);
        } 
        else {
            // Jika berat dalam rentang yang diinginkan
            printf("Weight is within the acceptable range. Current weight: %.2f grams\n", current_weight);
        }

        iteration_count++;  // Increment counter setelah setiap iterasi
    }
}

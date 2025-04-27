#include <stdio.h>
#include <stdbool.h>  // Untuk menggunakan bool

/* Fungsi untuk mengaktifkan atau menonaktifkan Pneumatic Piston */
void control_pneumatic_piston(bool state)
{
    if (state) {
        // Simulasi aktivasi piston
        printf("Pneumatic Piston Activated (True)\n");
    } else {
        // Simulasi deaktivasi piston
        printf("Pneumatic Piston Deactivated (False)\n");
    }
}

/* Fungsi utama dengan logika while untuk memonitor status dan mengontrol piston */
void monitor_pneumatic_piston(void) {
    bool piston_state = false;  // Awalnya piston dalam keadaan nonaktif
    int iteration_count = 0;  // Counter untuk menghitung iterasi (membatasi loop)

    // Loop hanya akan berjalan 5 kali
    while (iteration_count < 5) {
        // Logika untuk memutuskan apakah piston harus aktif atau nonaktif
        if (iteration_count % 2 == 0) {
            piston_state = true;  // Aktifkan piston pada iterasi genap
        } else {
            piston_state = false;  // Nonaktifkan piston pada iterasi ganjil
        }

        // Panggil fungsi untuk mengontrol pneumatic piston
        control_pneumatic_piston(piston_state);

        iteration_count++;  // Increment counter setelah setiap iterasi
    }
}

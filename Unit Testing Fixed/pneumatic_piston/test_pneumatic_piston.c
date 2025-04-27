#include "unity.h"
#include "pneumatic_piston.h"  // Menyertakan header fungsi yang diuji
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Buffer untuk menangkap output printf
char output_buffer[1024];  // Pastikan buffer cukup besar untuk menangkap output

// Fungsi mock untuk menggantikan printf
int mock_fputc(int c, FILE *stream) {
    if (stream == stdout) {
        // Menangkap karakter output ke dalam buffer
        size_t len = strlen(output_buffer);
        if (len < sizeof(output_buffer) - 1) {
            output_buffer[len] = c;
            output_buffer[len + 1] = '\0';  // Pastikan buffer diakhiri dengan null character
        }
    }
    return c;
}

// Fungsi yang dijalankan sebelum setiap tes
void setUp(void) {
    // Bersihkan buffer sebelum setiap tes
    memset(output_buffer, 0, sizeof(output_buffer));
}

// Fungsi yang dijalankan setelah setiap tes
void tearDown(void) {
    // Pembersihan setelah tes, jika diperlukan
}

// Test untuk memastikan monitor_pneumatic_piston berjalan dengan baik
void test_MonitorPneumaticPiston(void) {
    monitor_pneumatic_piston();  // Memanggil fungsi utama untuk memonitor piston

    // Verifikasi bahwa output sesuai dengan apa yang diharapkan
    TEST_ASSERT_TRUE(strstr(output_buffer, "Pneumatic Piston Activated (True)") != NULL);
    TEST_ASSERT_TRUE(strstr(output_buffer, "Pneumatic Piston Deactivated (False)") != NULL);
}

// Fungsi utama untuk menjalankan semua tes
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_MonitorPneumaticPiston);
    return UNITY_END();
}

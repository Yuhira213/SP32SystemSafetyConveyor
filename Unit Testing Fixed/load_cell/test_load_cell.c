#include "unity.h"
#include "load_cell.h"
#include <stdio.h>

// Deklarasi pointer fungsi untuk mocking
float (*mock_read_load_cell)(void);

// Fungsi mock untuk read_load_cell
float mock_read_load_cell_impl_1(void) {
    return 1000.0f;  // Simulasi nilai berat dalam rentang yang diterima
}

float mock_read_load_cell_impl_2(void) {
    return 900.0f;  // Simulasi nilai berat di bawah batas bawah (misalnya 900 gram)
}

float mock_read_load_cell_impl_3(void) {
    return 1100.0f;  // Simulasi nilai berat di atas batas atas (misalnya 1100 gram)
}

// Fungsi yang dijalankan sebelum setiap tes
void setUp(void) {
    // Inisialisasi pointer fungsi untuk mocking
    mock_read_load_cell = mock_read_load_cell_impl_1;  // Mengarah ke fungsi mock default (1000 gram)
}

// Fungsi yang dijalankan setelah setiap tes
void tearDown(void) {
    // Tidak ada pembersihan yang diperlukan saat ini
}

// Test untuk memastikan monitor_load_cell_weight berjalan dengan baik dalam rentang
void test_MonitorLoadCell_Weight_In_Range(void) {
    // Mocking nilai untuk berada dalam rentang yang diterima
    mock_read_load_cell = mock_read_load_cell_impl_1;  // Menggunakan mock dengan nilai 1000 gram

    monitor_load_cell_weight();
    TEST_PASS();  // Verifikasi tidak ada peringatan keluar
}

// Test untuk memastikan peringatan muncul jika berat kurang dari 950 gram
void test_MonitorLoadCell_Weight_Below_Lower_Limit(void) {
    // Mocking nilai untuk berada di bawah batas bawah (misalnya 900 gram)
    mock_read_load_cell = mock_read_load_cell_impl_2;  // Menggunakan mock dengan nilai 900 gram

    monitor_load_cell_weight();
    TEST_PASS();  // Verifikasi peringatan berat kurang dari batas bawah
}

// Test untuk memastikan peringatan muncul jika berat lebih dari 1050 gram
void test_MonitorLoadCell_Weight_Above_Upper_Limit(void) {
    // Mocking nilai untuk berada di atas batas atas (misalnya 1100 gram)
    mock_read_load_cell = mock_read_load_cell_impl_3;  // Menggunakan mock dengan nilai 1100 gram

    monitor_load_cell_weight();
    TEST_PASS();  // Verifikasi peringatan berat lebih dari batas atas
}

// Fungsi utama untuk menjalankan semua tes
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_MonitorLoadCell_Weight_In_Range);
    RUN_TEST(test_MonitorLoadCell_Weight_Below_Lower_Limit);
    RUN_TEST(test_MonitorLoadCell_Weight_Above_Upper_Limit);
    return UNITY_END();
}

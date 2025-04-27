#include "unity.h"
#include "buzzer.h"

// Mock untuk status buzzer
static uint8_t buzzer_status = 0;  // Status buzzer (0 = mati, 1 = hidup)

// Fungsi yang dijalankan sebelum setiap tes
void setUp(void) {
    // Inisialisasi atau reset kondisi sebelum tes
    buzzer_status = 0;  // Set buzzer awalnya mati
}

// Fungsi yang dijalankan setelah setiap tes
void tearDown(void) {
    // Tidak ada yang perlu dibersihkan saat ini
}

// Test untuk inisialisasi buzzer
void test_Buzzer_Init(void) {
    Buzzer_Init();
    TEST_ASSERT_EQUAL_UINT8(0, Buzzer_GetStatus());  // Buzzer harus dalam keadaan mati (0)
}

// Test untuk menghidupkan buzzer
void test_Buzzer_Control_ON(void) {
    Buzzer_Control(1);  // Hidupkan buzzer
    TEST_ASSERT_EQUAL_UINT8(1, Buzzer_GetStatus());  // Buzzer harus dalam keadaan hidup (1)
}

// Test untuk mematikan buzzer
void test_Buzzer_Control_OFF(void) {
    Buzzer_Control(0);  // Matikan buzzer
    TEST_ASSERT_EQUAL_UINT8(0, Buzzer_GetStatus());  // Buzzer harus dalam keadaan mati (0)
}

// Test untuk membaca status buzzer
void test_Buzzer_GetStatus(void) {
    Buzzer_Control(1);  // Hidupkan buzzer
    TEST_ASSERT_EQUAL_UINT8(1, Buzzer_GetStatus());  // Status buzzer harus 1 (hidup)

    Buzzer_Control(0);  // Matikan buzzer
    TEST_ASSERT_EQUAL_UINT8(0, Buzzer_GetStatus());  // Status buzzer harus 0 (mati)
}

// Fungsi utama untuk menjalankan semua tes
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Buzzer_Init);
    RUN_TEST(test_Buzzer_Control_ON);
    RUN_TEST(test_Buzzer_Control_OFF);
    RUN_TEST(test_Buzzer_GetStatus);
    return UNITY_END();
}

#include "unity.h"
#include "pushbutton.h"

// Mock untuk status tombol (untuk pengujian tanpa GPIO)
static uint8_t button_status = 0;  // Status tombol (0 = tidak ditekan, 1 = ditekan)


// Fungsi yang dijalankan sebelum setiap tes
void setUp(void) {
    // Reset status tombol sebelum setiap tes
    button_status = 0;
}

// Fungsi yang dijalankan setelah setiap tes
void tearDown(void) {
    // Tidak ada yang perlu dibersihkan saat ini
}

// Test untuk inisialisasi tombol
void test_PushButton_Init(void) {
    PushButton_Init();
    TEST_ASSERT_EQUAL_UINT8(0, button_status);  // Tombol harus dalam keadaan tidak ditekan (0)
}

// Test untuk mengaktifkan tombol
void test_PushButton_Control_ON(void) {
    PushButton_Control(1);  // Set tombol ke ON
    TEST_ASSERT_EQUAL_UINT8(1, button_status);  // Tombol harus dalam keadaan ditekan (1)
}

// Test untuk menonaktifkan tombol
void test_PushButton_Control_OFF(void) {
    PushButton_Control(0);  // Set tombol ke OFF
    TEST_ASSERT_EQUAL_UINT8(0, button_status);  // Tombol harus dalam keadaan tidak ditekan (0)
}

// Test untuk membaca status tombol
void test_PushButton_Read(void) {
    PushButton_Control(1);  // Tombol ditekan
    TEST_ASSERT_EQUAL_UINT8(1, PushButton_Read());  // Status tombol harus 1 (ditekan)

    PushButton_Control(0);  // Tombol tidak ditekan
    TEST_ASSERT_EQUAL_UINT8(0, PushButton_Read());  // Status tombol harus 0 (tidak ditekan)
}

// Fungsi utama untuk menjalankan semua tes
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_PushButton_Init);
    RUN_TEST(test_PushButton_Control_ON);
    RUN_TEST(test_PushButton_Control_OFF);
    RUN_TEST(test_PushButton_Read);
    return UNITY_END();
}

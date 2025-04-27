#include "unity.h"
#include "relay.h"

// Setup dan teardown untuk unit test
void setUp(void) {
    // Setup sebelum setiap tes
}

void tearDown(void) {
    // Cleanup setelah setiap tes
}

// Test untuk Relay_Init
void test_Relay_Init(void) {
    // Panggil fungsi inisialisasi
    Relay_Init();
    
    // Verifikasi bahwa status relay adalah 0 (OFF)
    TEST_ASSERT_EQUAL_UINT8(0, relay_status);  // Anda perlu mengganti `relay_status` dengan cara untuk memeriksa status relay
}

// Test untuk Relay_Control saat status ON
void test_Relay_Control_ON(void) {
    Relay_Control(1);  // Menghidupkan relay
    
    // Verifikasi bahwa relay dinyalakan
    TEST_ASSERT_EQUAL_UINT8(1, relay_status);  // Anda perlu mengganti `relay_status` dengan cara untuk memeriksa status relay
}

// Test untuk Relay_Control saat status OFF
void test_Relay_Control_OFF(void) {
    Relay_Control(0);  // Mematikan relay
    
    // Verifikasi bahwa relay dimatikan
    TEST_ASSERT_EQUAL_UINT8(0, relay_status);  // Anda perlu mengganti `relay_status` dengan cara untuk memeriksa status relay
}

// Fungsi utama untuk menjalankan semua unit test
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Relay_Init);
    RUN_TEST(test_Relay_Control_ON);
    RUN_TEST(test_Relay_Control_OFF);
    return UNITY_END();
}

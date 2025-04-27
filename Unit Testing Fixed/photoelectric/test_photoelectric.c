#include "unity.h"
#include "photoelectric.h"

// Setup dan teardown untuk unit test
void setUp(void) {
    // Setup sebelum setiap tes
}

void tearDown(void) {
    // Cleanup setelah setiap tes
}

// Test untuk Photoelectric_Init
void test_Photoelectric_Init(void) {
    Photoelectric_Init();
    // Verifikasi bahwa status sensor setelah inisialisasi adalah 0 (tidak terhalang)
    TEST_ASSERT_EQUAL_UINT8(0, Photoelectric_Read());
}

// Test untuk Photoelectric_Read saat sensor terhalang
void test_Photoelectric_Read_Obstacle(void) {
    Photoelectric_SetStatus(1);  // Set sensor status ke terhalang (1)
    
    // Verifikasi bahwa Photoelectric_Read mengembalikan 1 (terhalang)
    TEST_ASSERT_EQUAL_UINT8(1, Photoelectric_Read());
}

// Test untuk Photoelectric_Read saat sensor tidak terhalang
void test_Photoelectric_Read_NoObstacle(void) {
    Photoelectric_SetStatus(0);  // Set sensor status ke tidak terhalang (0)

    // Verifikasi bahwa Photoelectric_Read mengembalikan 0 (tidak terhalang)
    TEST_ASSERT_EQUAL_UINT8(0, Photoelectric_Read());
}

// Fungsi utama untuk menjalankan semua unit test
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Photoelectric_Init);
    RUN_TEST(test_Photoelectric_Read_Obstacle);
    RUN_TEST(test_Photoelectric_Read_NoObstacle);
    return UNITY_END();
}

#include "photoelectric.h"

/*
 * Rule: DCL31-C
 * Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.
 */
void Photoelectric_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    // Aktifkan clock port sensor
    __HAL_RCC_GPIOA_CLK_ENABLE();  // Rule: MSC30-C - Hindari akses tanpa clock. Mengaktifkan clock untuk GPIO port A agar bisa digunakan.

    GPIO_InitStruct.Pin = PHOTOELECTRIC_PIN;  // Rule: STR30-C - Penamaan yang jelas dan deskriptif untuk pin fotoelektrik.
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;  // Rule: EXP33-C - Mengonfigurasi pin sebagai input sesuai dengan fungsinya.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down pada input fotoelektrik.

    HAL_GPIO_Init(PHOTOELECTRIC_GPIO_PORT, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi pin fotoelektrik dengan konfigurasi yang sesuai.
}

/*
 * Rule: EXP33-C
 * Jangan gunakan variabel tak diinisialisasi atau nilai tak terdefinisi.
 * Rule: INT13-C
 * Gunakan operasi logika dan pembandingan dengan tepat.
 */
uint8_t Photoelectric_Read(void) {
    GPIO_PinState state = HAL_GPIO_ReadPin(PHOTOELECTRIC_GPIO_PORT, PHOTOELECTRIC_PIN);  // Rule: EXP33-C - Pastikan pembacaan pin dilakukan dengan benar.

    if (state == GPIO_PIN_RESET) {  // Rule: INT13-C - Operasi pembandingan dilakukan dengan tepat. Menggunakan `GPIO_PIN_RESET` untuk memeriksa status pin.
        return 1U;  // Terhalang (aktif LOW)
    } else {
        return 0U;  // Tidak terhalang
    }
}

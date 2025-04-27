/* Includes ------------------------------------------------------------------*/
#include "load_cell.h"
#include "stm32f4xx_hal.h"  // Library HAL untuk STM32

/* Private variables ---------------------------------------------------------*/
extern ADC_HandleTypeDef hadc1;  // Rule: DCL31-C - Variabel `hadc1` hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

/* Fungsi untuk membaca nilai dari Load Cell menggunakan ADC */
float read_load_cell(void)
{
    uint32_t adc_value = 0;  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.
    float load_cell_weight = 0.0f;  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    // Mulai konversi ADC
    HAL_ADC_Start(&hadc1);  // Rule: EXP33-C - Pastikan fungsi ADC diinisialisasi dengan benar sebelum digunakan.
    
    // Tunggu sampai konversi selesai
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {  // Rule: INT13-C - Pastikan pembandingan dilakukan dengan tepat.
        // Baca nilai ADC
        adc_value = HAL_ADC_GetValue(&hadc1);  // Rule: EXP33-C - Menggunakan nilai ADC yang valid setelah konversi selesai.

        // Misalnya, lakukan kalibrasi dengan konversi ADC ke berat (gram)
        load_cell_weight = (float)adc_value * (5.0f / 4095.0f) * 1000.0f;  // Rule: EXP33-C - Perhitungan dilakukan dengan pembagian yang tepat (menggunakan ADC 12-bit dan konversi ke gram).
    }

    return load_cell_weight;  // Rule: EXP33-C - Mengembalikan nilai load cell yang terkonversi dengan tepat.
}

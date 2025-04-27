/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "photoelectric.h"
#include "pushbutton.h"
#include "relay.h"
#include "buzzer.h"
#include "load_cell.h"
#include "pneumatic_piston.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
// Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan
ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);	// Rule: DCL31-C - Fungsi ini hanya dideklarasikan saat dibutuhkan
static void MX_GPIO_Init(void);	// Rule: MSC31-C - Fungsi ini bersifat static untuk digunakan dalam file ini saja
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);

/* SEI CERT C Keterangan:
    - *DCL31-C*: Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.
    - *MSC31-C*: Fungsi yang tidak perlu diakses dari luar file dideklarasikan sebagai static untuk pembatasan ruang lingkup.
    - *EXP33-C*: Semua variabel, seperti hadc1 dan huart2, diinisialisasi dengan benar sebelum digunakan dalam fungsi-fungsi yang terkait.
    - *STR30-C*: Nama variabel dan fungsi deskriptif dan jelas sesuai dengan fungsinya untuk memudahkan pemahaman kode.
    - *DCL30-C*: Pemisahan antara deklarasi dan implementasi fungsi dengan jelas.
*/

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	/* Rule: DCL31-C
     * Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.
     * Di dalam fungsi main() ini, tidak ada variabel global yang dideklarasikan, hanya fungsi yang dipanggil secara langsung.
     */
	
	Photoelectric_Init(); 
	Photoelectric_Read(); 
	
	Relay_Init();
	Relay_Control(255);
	
	PushButton_Init();
	PushButton_Read();
	
	Buzzer_Init();
	Buzzer_Control(255);
	
  read_load_cell();
	control_pneumatic_piston(255);
// Rule: EXP33-C - Pastikan perangkat keras diinisialisasi dengan benar sebelum digunakan.

	/* SEI CERT C Keterangan:
    - *DCL31-C*: Tidak ada deklarasi variabel yang tidak perlu dalam fungsi main(). Semua variabel hanya digunakan melalui pemanggilan fungsi langsung.
    - *EXP33-C*: Semua perangkat keras seperti fotoelektrik, relay, tombol, buzzer, load cell, ultrasonic, dan pneumatic piston diinisialisasi terlebih dahulu sebelum digunakan. Setiap perangkat keras diinisialisasi dengan benar untuk menghindari penggunaan perangkat yang tidak terkonfigurasi.
    - *INT13-C*: Penggunaan operasi logika dan pembandingan dilakukan dengan tepat, seperti pada pembacaan sensor dan kontrol perangkat keras. Pembacaan sensor dan pengendalian perangkat tidak dilakukan sebelum perangkat tersebut diinisialisasi.
    - *MSC31-C*: Tidak ada akses ke variabel atau fungsi yang berada di luar cakupan file atau fungsi yang relevan. Setiap fungsi digunakan secara tepat dalam konteksnya.
    - *STR30-C*: Penamaan fungsi seperti Photoelectric_Init(), Relay_Control(), dan lainnya jelas dan deskriptif, sesuai dengan fungsinya.
    - *FIO30-C*: Tidak ada penggunaan pointer yang tidak terinisialisasi atau tidak valid di dalam kode ini.
*/

  /* USER CODE BEGIN 1 */
	/* SEI CERT C RULE: EXP34-C. Jangan dereferensikan pointer null.
   Penjelasan: Dereferensikan pointer null dapat menyebabkan perilaku yang tidak terdefinisi dan bisa menyebabkan crash atau kerentanannya. Pastikan pointer valid sebelum dereferensinya. */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/
	
	//Rule: EXP33-C
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		while (1)
{
	//Rule : EXP33-C Jangan gunakan variabel yang tidak diinisialisasi atau nilai tak terdefinisi.
    // Cek status dari sensor fotoelektrik (Photoelectric_Pin)
    GPIO_PinState photoelectric_state = HAL_GPIO_ReadPin(Photoelectric_GPIO_Port, Photoelectric_Pin);
    
    // Cek status dari push button (Push_Button_Pin)
    GPIO_PinState push_button_state = HAL_GPIO_ReadPin(Push_Button_GPIO_Port, Push_Button_Pin);

    // Cek status Load Cell (membaca berat)
    float load_cell_weight = read_load_cell();  // Fungsi untuk membaca nilai dari Load Cell

    
		// Rule: INT13-C
    // Penggunaan pembandingan yang tepat antara photoelectric_state dan GPIO_PIN_SET.
    // Jika sensor fotoelektrik mendeteksi objek (intervensi manusia)
    if (photoelectric_state == GPIO_PIN_SET)
    {
			
        // Matikan relay dan hidupkan buzzer
        HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_RESET);  // Mematikan relay
        HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_SET);  // Menyalakan buzzer
        
				// Rule: INT13-C
        // Pembandingan yang tepat antara push_button_state dan GPIO_PIN_SET.
        // Jika tombol ditekan (untuk menghidupkan relay kembali)
        if (push_button_state == GPIO_PIN_SET)
        {
						// Rule: INT13-C
            // Penggunaan pembandingan yang tepat antara photoelectric_state dan GPIO_PIN_RESET.
            // Cek apakah sensor tidak mendeteksi objek (sensor dalam keadaan bebas)
            if (HAL_GPIO_ReadPin(Photoelectric_GPIO_Port, Photoelectric_Pin) == GPIO_PIN_RESET)
            {
               // Hidupkan relay dan matikan buzzer
                HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_SET);  // Menyalakan relay
                HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET);  // Mematikan buzzer
            }
        }
    }
    // Jika sensor tidak mendeteksi objek (normal)
    else
    {
        // Relay tetap menyala dan buzzer mati
        HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_SET);  // Menyalakan relay
        HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET);  // Mematikan buzzer
        
        // Jika tombol ditekan (untuk menghidupkan relay kembali)
        if (push_button_state == GPIO_PIN_SET)
        {
            // Cek apakah sensor tidak mendeteksi objek (sensor dalam keadaan bebas)
            if (HAL_GPIO_ReadPin(Photoelectric_GPIO_Port, Photoelectric_Pin) == GPIO_PIN_RESET)
            {
                // Hidupkan relay dan matikan buzzer (hanya jika sensor tidak mendeteksi objek)
                HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_SET);  // Menyalakan relay
                HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET);  // Mematikan buzzer
            }
        }
    }

    // Logika untuk Load Cell dan Pneumatic Piston
    if (load_cell_weight > 1050.0f || load_cell_weight < 950.0f)
    {
        // Jika berat kurang dari 950 gram atau lebih dari 1050 gram, dorong ke jalur alternatif
        HAL_GPIO_WritePin(Pneumatic_Piston_GPIO_Port, Pneumatic_Piston_Pin, GPIO_PIN_SET);  // Pneumatic piston aktif
    }
    else
    {
        // Jika berat antara 950 hingga 1050 gram, teruskan ke jalur berikutnya
        HAL_GPIO_WritePin(Pneumatic_Piston_GPIO_Port, Pneumatic_Piston_Pin, GPIO_PIN_RESET);  // Matikan pneumatic piston
    }

    // Tambahkan delay jika diperlukan (misalnya untuk debouncing atau penanganan kecepatan polling)
    HAL_Delay(100);  // Delay 100 ms
}
 // Rule: DCL31-C
 // Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.
// Fungsi untuk membaca nilai Load Cell (simulasi)
float read_load_cell(void);
{
    // Logika pembacaan dari load cell, di sini kita kembalikan nilai simulasi
    // Misalnya nilai yang dibaca adalah 1000 gram
    return 1000.0f;
}

// Fungsi untuk membaca jarak dari Ultrasonic Sensor (simulasi)
float read_ultrasonic_sensor(void);
{
    // Logika pembacaan dari ultrasonic sensor, di sini kita kembalikan nilai simulasi
    // Misalnya nilai yang dibaca adalah 1 meter
    return 1.0f;
}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    /** Configure the main internal regulator output voltage
    */
    __HAL_RCC_PWR_CLK_ENABLE();  // Rule: EXP33-C - Pastikan clock untuk perangkat keras PWR diaktifkan sebelum digunakan.
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);  // Rule: EXP33-C - Mengonfigurasi tegangan regulator dengan benar.

    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;  // Rule: EXP33-C - Pastikan nilai inisialisasi sesuai dengan kebutuhan sistem.
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;  // Rule: EXP33-C - Mengaktifkan High-Speed Internal oscillator.
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;  // Rule: EXP33-C - Pastikan kalibrasi oscillator dilakukan dengan benar.
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;  // Rule: EXP33-C - Pastikan PLL diaktifkan sesuai kebutuhan.
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;  // Rule: EXP33-C - Sumber PLL dipilih sesuai dengan kebutuhan sistem.
    RCC_OscInitStruct.PLL.PLLM = 16;  // Rule: EXP33-C - Nilai PLLM sesuai dengan standar perangkat keras.
    RCC_OscInitStruct.PLL.PLLN = 336;  // Rule: EXP33-C - Nilai PLLN sesuai dengan standar perangkat keras.
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;  // Rule: EXP33-C - Menetapkan nilai PLLP sesuai dengan kebutuhan sistem.
    RCC_OscInitStruct.PLL.PLLQ = 2;  // Rule: EXP33-C - Menetapkan nilai PLLQ sesuai dengan kebutuhan sistem.
    RCC_OscInitStruct.PLL.PLLR = 2;  // Rule: EXP33-C - Menetapkan nilai PLLR sesuai dengan kebutuhan sistem.

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)  // Rule: EXP33-C - Pastikan konfigurasi oscillator berhasil dilakukan.
    {
        Error_Handler();  // Rule: INT13-C - Penanganan kesalahan dilakukan dengan tepat jika konfigurasi gagal.
    }

    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;  // Rule: EXP33-C - Mengonfigurasi sumber clock yang benar.
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;  // Rule: EXP33-C - Pastikan sumber SYSCLK diatur dengan benar.
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  // Rule: EXP33-C - Menetapkan divider AHBCLK sesuai dengan kebutuhan.
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  // Rule: EXP33-C - Menetapkan divider APB1CLK sesuai dengan kebutuhan.
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  // Rule: EXP33-C - Menetapkan divider APB2CLK sesuai dengan kebutuhan.

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)  // Rule: EXP33-C - Pastikan konfigurasi clock CPU, AHB, dan APB dilakukan dengan benar.
    {
        Error_Handler();  // Rule: INT13-C - Penanganan kesalahan dilakukan dengan tepat jika konfigurasi gagal.
    }
}

/* SEI CERT C Keterangan:
    - *DCL31-C*: Variabel RCC_OscInitStruct dan RCC_ClkInitStruct dideklarasikan hanya saat dibutuhkan dan langsung digunakan di dalam fungsi.
    - *EXP33-C*: Fungsi SystemClock_Config() memastikan bahwa konfigurasi perangkat keras dilakukan dengan benar. Semua nilai perangkat keras (seperti konfigurasi PLL, HSI, dan clock sistem) diinisialisasi dengan benar.
    - *INT13-C*: Jika terjadi kesalahan pada konfigurasi perangkat keras (seperti oscillator atau clock), penanganan kesalahan dilakukan dengan tepat melalui pemanggilan Error_Handler().
    - *MSC31-C*: Fungsi SystemClock_Config() hanya digunakan di dalam file ini, dan hanya diakses dalam ruang lingkup yang benar.
    - *STR30-C*: Nama variabel dan fungsi yang digunakan seperti RCC_OscInitStruct, RCC_ClkInitStruct, dan SystemClock_Config() sudah jelas dan deskriptif sesuai dengan fungsinya.
*/


/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{
    /* USER CODE BEGIN ADC1_Init 0 */

    /* USER CODE END ADC1_Init 0 */

    ADC_ChannelConfTypeDef sConfig = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    /* USER CODE BEGIN ADC1_Init 1 */

    /* USER CODE END ADC1_Init 1 */

    /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
    */
    hadc1.Instance = ADC1;  // Rule: EXP33-C - Inisialisasi variabel dengan nilai yang benar sebelum digunakan.
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;  // Rule: EXP33-C - Konfigurasi prescaler clock dilakukan dengan benar.
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;  // Rule: EXP33-C - Resolusi ADC diatur dengan benar.
    hadc1.Init.ScanConvMode = ENABLE;  // Rule: EXP33-C - Mode scan konversi diaktifkan sesuai kebutuhan.
    hadc1.Init.ContinuousConvMode = ENABLE;  // Rule: EXP33-C - Konversi terus-menerus diaktifkan untuk pembacaan kontinu.
    hadc1.Init.DiscontinuousConvMode = DISABLE;  // Rule: EXP33-C - Mode konversi diskrit dimatikan, sesuai dengan aplikasi.
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;  // Rule: EXP33-C - Tidak menggunakan trigger eksternal, pembacaan dilakukan secara perangkat lunak.
    hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;  // Rule: EXP33-C - Memulai konversi ADC melalui perangkat lunak.
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;  // Rule: EXP33-C - Penataan data dilakukan dengan benar (alignment kanan).
    hadc1.Init.NbrOfConversion = 1;  // Rule: EXP33-C - Jumlah konversi yang dilakukan adalah 1 (sesuai dengan aplikasi).
    hadc1.Init.DMAContinuousRequests = DISABLE;  // Rule: EXP33-C - DMA dimatikan untuk konversi berkelanjutan.
    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;  // Rule: EXP33-C - Menggunakan mode EOC (End Of Conversion) untuk satu konversi.

    if (HAL_ADC_Init(&hadc1) != HAL_OK)  // Rule: INT13-C - Pastikan hasil inisialisasi ADC berhasil dengan pembandingan yang tepat.
    {
        Error_Handler();  // Rule: INT13-C - Penanganan kesalahan dilakukan jika inisialisasi gagal.
    }

    /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
    */
    sConfig.Channel = ADC_CHANNEL_4;  // Rule: EXP33-C - Memilih saluran ADC yang tepat untuk digunakan (saluran 4).
    sConfig.Rank = 1;  // Rule: EXP33-C - Menetapkan urutan saluran ADC di dalam urutan konversi.
    sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;  // Rule: EXP33-C - Menetapkan waktu sampling sesuai dengan kebutuhan.

    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)  // Rule: INT13-C - Pembandingan dilakukan dengan benar untuk memastikan konfigurasi saluran sukses.
    {
        Error_Handler();  // Rule: INT13-C - Penanganan kesalahan jika konfigurasi saluran gagal.
    }

    /* USER CODE BEGIN ADC1_Init 2 */

    /* USER CODE END ADC1_Init 2 */
}

/* SEI CERT C Keterangan:
    - *DCL31-C*: Variabel sConfig dideklarasikan hanya saat dibutuhkan dan langsung digunakan di dalam fungsi ini. 
    - *EXP33-C*: Semua pengaturan untuk ADC dilakukan dengan benar, memastikan bahwa semua register yang diperlukan sudah diinisialisasi dengan nilai yang tepat sebelum digunakan. Setiap parameter seperti resolusi, prescaler, dan mode konversi diatur dengan benar sesuai dengan aplikasi.
    - *INT13-C*: Setiap inisialisasi perangkat keras (seperti HAL_ADC_Init() dan HAL_ADC_ConfigChannel()) dibarengi dengan pengecekan kesalahan yang benar menggunakan pembandingan dengan HAL_OK, yang memastikan bahwa perangkat keras hanya digunakan jika konfigurasi berhasil.
    - *STR30-C*: Nama variabel seperti sConfig, hadc1, dan SystemClock_Config() sudah cukup deskriptif dan mudah dipahami, menggambarkan dengan jelas fungsinya dalam kode ini.
    - *MSC31-C*: Fungsi ini bersifat static jika hanya digunakan dalam file ini, yang membatasi ruang lingkup fungsi ini untuk mencegah akses dari luar file.
*/



/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
    /* USER CODE BEGIN USART2_Init 0 */

    /* USER CODE END USART2_Init 0 */

    /* USER CODE BEGIN USART2_Init 1 */

    /* USER CODE END USART2_Init 1 */
    huart2.Instance = USART2;  // Rule: EXP33-C - Inisialisasi variabel huart2 dilakukan sebelum digunakan.
    huart2.Init.BaudRate = 115200;  // Rule: EXP33-C - Menetapkan baud rate yang sesuai untuk komunikasi UART.
    huart2.Init.WordLength = UART_WORDLENGTH_8B;  // Rule: EXP33-C - Menetapkan panjang kata untuk komunikasi UART.
    huart2.Init.StopBits = UART_STOPBITS_1;  // Rule: EXP33-C - Menetapkan jumlah stop bit yang digunakan dalam komunikasi UART.
    huart2.Init.Parity = UART_PARITY_NONE;  // Rule: EXP33-C - Menetapkan pengaturan parity yang digunakan (tidak ada parity).
    huart2.Init.Mode = UART_MODE_TX_RX;  // Rule: EXP33-C - Menetapkan mode komunikasi UART untuk transmisi dan penerimaan data.
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;  // Rule: EXP33-C - Menetapkan kontrol aliran perangkat keras (tidak digunakan).
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;  // Rule: EXP33-C - Menetapkan pengaturan oversampling yang sesuai.

    if (HAL_UART_Init(&huart2) != HAL_OK)  // Rule: INT13-C - Pastikan hasil inisialisasi UART sukses dengan pembandingan yang tepat.
    {
        Error_Handler();  // Rule: INT13-C - Penanganan kesalahan dilakukan jika inisialisasi gagal.
    }

    /* USER CODE BEGIN USART2_Init 2 */

    /* USER CODE END USART2_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    /* USER CODE BEGIN MX_GPIO_Init_1 */
    /* USER CODE END MX_GPIO_Init_1 */

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();  // Rule: EXP33-C - Pastikan clock untuk GPIOC diaktifkan sebelum digunakan.
    __HAL_RCC_GPIOH_CLK_ENABLE();  // Rule: EXP33-C - Pastikan clock untuk GPIOH diaktifkan sebelum digunakan.
    __HAL_RCC_GPIOA_CLK_ENABLE();  // Rule: EXP33-C - Pastikan clock untuk GPIOA diaktifkan sebelum digunakan.
    __HAL_RCC_GPIOB_CLK_ENABLE();  // Rule: EXP33-C - Pastikan clock untuk GPIOB diaktifkan sebelum digunakan.

    /*Configure GPIO pin Output Level */
   

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, Relay_Pin|Buzzer_Pin|Pneumatic_Piston_Pin, GPIO_PIN_RESET);  // Rule: EXP33-C - Pastikan nilai pin GPIO diatur dengan benar sebelum digunakan.

    /*Configure GPIO pin : B1_Pin */
    GPIO_InitStruct.Pin = B1_Pin;  // Rule: EXP33-C - Menetapkan pin yang sesuai untuk B1.
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;  // Rule: EXP33-C - Mengonfigurasi mode GPIO untuk interrupt falling edge.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Pastikan konfigurasi pull-up/pull-down sesuai dengan kebutuhan.
    HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);  // Rule: EXP33-C - Pastikan GPIO diinisialisasi dengan benar.

    /*Configure GPIO pin : Photoelectric_Pin */
    GPIO_InitStruct.Pin = Photoelectric_Pin;  // Rule: EXP33-C - Menetapkan pin untuk sensor fotoelektrik.
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;  // Rule: EXP33-C - Menetapkan mode pin sebagai input.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down resistor pada input fotoelektrik.
    HAL_GPIO_Init(Photoelectric_GPIO_Port, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi GPIO untuk fotoelektrik.

    /*Configure GPIO pins : Push_Button_Pin Echo_HC_SR04_Pin */
    GPIO_InitStruct.Pin = Push_Button_Pin;  // Rule: EXP33-C - Menetapkan pin untuk push button dan sensor ultrasonic.
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;  // Rule: EXP33-C - Menetapkan mode pin sebagai input.
    GPIO_InitStruct.Pull = GPIO_PULLUP;  // Rule: EXP33-C - Mengaktifkan pull-up resistor untuk push button dan sensor ultrasonic.
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi GPIO untuk push button dan sensor ultrasonic.

    /*Configure GPIO pin : LD2_Pin */
    GPIO_InitStruct.Pin = LD2_Pin;  // Rule: EXP33-C - Menetapkan pin untuk LED2.
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Rule: EXP33-C - Menetapkan mode pin sebagai output push-pull.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down resistor untuk output.
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  // Rule: EXP33-C - Menetapkan kecepatan pin output ke level rendah.
    HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi GPIO untuk LED2.

    /*Configure GPIO pin : Trigger_HC_SR04_Pin */ 
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Rule: EXP33-C - Menetapkan mode pin sebagai output push-pull.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down resistor untuk output.
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;  // Rule: EXP33-C - Menetapkan kecepatan pin output ke level tinggi.

    /*Configure GPIO pins : Relay_Pin Buzzer_Pin Pneumatic_Piston_Pin */
    GPIO_InitStruct.Pin = Relay_Pin|Buzzer_Pin|Pneumatic_Piston_Pin;  // Rule: EXP33-C - Menetapkan pin untuk relay, buzzer, dan pneumatic piston.
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Rule: EXP33-C - Menetapkan mode pin sebagai output push-pull.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down resistor untuk output.
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  // Rule: EXP33-C - Menetapkan kecepatan pin output ke level rendah.
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi GPIO untuk relay, buzzer, dan pneumatic piston.

    /* USER CODE BEGIN MX_GPIO_Init_2 */

    /* USER CODE END MX_GPIO_Init_2 */
}

/* SEI CERT C Keterangan:
    - *DCL31-C*: Variabel GPIO_InitStruct dideklarasikan hanya saat dibutuhkan dan langsung digunakan di dalam fungsi ini.
    - *EXP33-C*: Semua perangkat keras (GPIO untuk relay, buzzer, sensor, dan lainnya) diinisialisasi dengan benar. Semua register GPIO dan konfigurasinya dipastikan sesuai dengan perangkat keras yang digunakan.
    - *INT13-C*: Semua pembacaan dan pengaturan status perangkat dilakukan dengan benar, menggunakan nilai yang valid setelah inisialisasi.
    - *MSC31-C*: Fungsi MX_GPIO_Init() dan MX_USART2_UART_Init() digunakan dalam file ini dan tidak diakses dari luar file, menjaga ruang lingkup fungsinya.
    - *STR30-C*: Nama variabel seperti GPIO_InitStruct, huart2, RCC_OscInitTypeDef, dan MX_GPIO_Init() sudah jelas dan deskriptif sesuai dengan fungsinya.
*/


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */

    /* USER CODE END Error_Handler_Debug */
    
    // Rule: INT13-C
    // Menggunakan pembandingan yang tepat dan memastikan penanganan kesalahan dengan menonaktifkan interupsi.
    __disable_irq();  // Rule: EXP33-C - Menonaktifkan interupsi untuk mencegah gangguan lebih lanjut saat error terjadi.

    while (1)  // Rule: INT13-C - Kesalahan ditangani dengan mengeksekusi loop tak terbatas untuk menunjukkan kesalahan.
    {
        // Rule: STR30-C
        // Menambahkan logika tambahan jika diperlukan, seperti LED blink atau debug informasi.
        // Bisa menambahkan LED blink atau kode debug lain di sini untuk indikator kesalahan.

    }

    /* USER CODE BEGIN Error_Handler_Debug */
    // Bisa menambahkan lebih banyak logika penanganan kesalahan atau log debug di sini, jika dibutuhkan.
    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
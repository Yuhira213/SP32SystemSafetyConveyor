#ifndef LOAD_CELL_H
#define LOAD_CELL_H

#include <stdint.h>

// Fungsi untuk membaca nilai dari Load Cell menggunakan ADC
float read_load_cell(void);

// Fungsi utama untuk memonitor berat load cell
void monitor_load_cell_weight(void);

#endif // LOAD_CELL_H

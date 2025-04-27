![Pemrograman Kontroller](https://github.com/user-attachments/assets/796ec06f-dec0-434b-bbf2-f1547aebe82d)
# “Sistem Safety Conveyor Packaging Minuman Botol Berbasis Sensor Photoelectric dan STM32F446RE dengan Fitur Deteksi Obstacle dan Penghentian Otomatis"
 
 Projek ini mendemonstrasikan bagaimana cara membuat program pada STM32 NUCLEO-F466RE dengan fungsi menghentikan Conveyor secara otomatis ketika mendeteksi adanya halangan yang terdeteksi, Guna meningkatkan Sistem Safety pada Conveyor

 ## Authors
1. Yudhistira Ananda Kuswantoro (2042231015)
2. Adam Fareliansah Malandi (2042231049)
3. Wildan Rizki Auzay (2042231061)
4. Ahmad Radhy (Supervisor)

## Features
1. **Testing Kinerja Interaktif Program melalui Compiler** : Dengan menggunakan Code C yang dapat dikompilasi pada C Compiler untuk mengasilkan output secara interaktif
2. **Unit Testing Unity dengan MSYS2 MINGW64** : Menggunakan aplikasi MSYS2 MINGW64 sebagai runner dari Unit Testing

## Requirements
### Software
1. STM32CubeMX
2. Keil µVision MDK
3. Visual Studio Code
4. MSYS2 MinGW64

### Extension and Library
1. C/C++ Extension Pack(di install dalam Visual Studio Code)
2. CMake Tools (Diinstall dalam Visual Studio Code)
3. GCC (install di dalam MSYS2 MinGW64) dengan menginput : ``` pacman -S mingw-w64-x86_64-gcc ```
4. Make (install di dalam MSYS2 MinGW64) dengan menginput : ``` pacman -S make ```
5. cmocka (install di dalam MSYS2 MinGW64) dengan menginput : ``` pacman -S mingw-w64-x86_64-cmocka ```

# Tutorial melakukan Testing 
### 1. Clone semua isi repository dengan unduh atau
```bash
git clone https://github.com/Yuhira213/STM32SafetyConveyorPRJ.git
```
### 2. Buka MSYS2 MinGW64
### 3. Masukkan directory dari folder Unit Testing 2
Sebagai contoh untuk saya menggunakan directory:
```bash 
cd "/c/STM32 Project/Conveyor_Safety Fixed/Unit Testing Fixed/photoelectric"
```
Atau bisa dilihat dalam file MSYS2 WINGW64 Directory.txt
### kemudian klik enter
### 4. Kemudian masukkan command
```bash 
make run
```
atau bisa dilihat di file MSYS2 WINGW64 Directory
### kemudian klik enter
### 5. Setelah itu akan muncul tampilan seperti pada gambar
![image](https://github.com/user-attachments/assets/57015532-7013-4b17-a299-545396902cbd)





cmake_minimum_required(VERSION 3.13)
project(conveyor_safety_test C)

set(CMAKE_C_STANDARD 99)

# Path ke cmocka, bisa pakai package manager pacman di MSYS2
find_package(cmocka REQUIRED)

# File sumber dan test
add_executable(run_tests
    main_logic.c
    test_main_logic.c
)

# Link ke cmocka
target_link_libraries(run_tests cmocka::cmocka)
set(CMAKE_TOOLCHAIN_FILE "C:/path_ke/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(/mingw64/include)
link_directories(/mingw64/lib)
target_link_libraries(run_tests cmocka)

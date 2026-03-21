cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico2)

include(pico_sdk_import.cmake)

project(main C CXX ASM)

pico_sdk_init()

add_executable(main
    main.c
)

include_directories(
    ./inc
)

add_subdirectory(lib/Config)
add_subdirectory(lib/e-Paper)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)

include_directories(
    ./lib/Config
    ./lib/GUI
    ./inc
)

target_link_libraries(main
    ePaper
    GUI
    Fonts
    Config
    pico_stdlib
    hardware_spi
    hardware_pio
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)

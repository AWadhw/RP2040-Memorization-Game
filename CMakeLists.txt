cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(trigger-led C CXX ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()



add_executable(triggerled
triggerled.c
)
pico_enable_stdio_usb(triggerled 1) 
pico_enable_stdio_uart(triggerled 0)


pico_add_extra_outputs(triggerled)

target_link_libraries(triggerled pico_stdlib)



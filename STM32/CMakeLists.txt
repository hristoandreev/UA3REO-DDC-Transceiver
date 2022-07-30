cmake_minimum_required(VERSION 3.17)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

set(PROJECT_NAME ${TARGET})

# specify cross-compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_VERBOSE_MAKEFILE FALSE CACHE BOOL "" FORCE)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

if (NOT TARGET)
    set(TARGET "WOLF")
endif()

if(${TARGET} STREQUAL "WOLF")
    add_subdirectory(WOLF/cmake)
elseif(${TARGET} STREQUAL "WOLF-Lite")

elseif(${TARGET} STREQUAL "WOLF-X1")

else()

endif()
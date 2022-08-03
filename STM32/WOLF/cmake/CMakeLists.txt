cmake_minimum_required(VERSION 3.17)

include(dependencies.cmake)
#include(${CMAKE_SOURCE_DIR}/toolchain.cmake)

message(STATUS "STM32_CUBE_PROGRAMMER_DIR -> " ${STM32_CUBE_PROGRAMMER})
message(STATUS "CMAKE_SOURCE_DIR -> " ${CMAKE_SOURCE_DIR})
message(STATUS "CMAKE_BINARY_DIR -> " ${CMAKE_BINARY_DIR})

set(STM32CubeProgrammer ${STM32_CUBE_PROGRAMMER}/bin/STM32_Programmer_CLI)
message(STATUS "STM32CubeProgrammer -> " ${STM32CubeProgrammer})

set(LcdImageConverter ${CMAKE_BINARY_DIR}/_deps/lcd-image-converter-src/lcd-image-converter.exe)
message(STATUS "ImageConverter -> " ${LcdImageConverter})

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/WOLF/cmake/STM32H743VITx_FLASH.ld")

# hardware floating point
add_compile_definitions(ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING;ARM_MATH_LOOPUNROLL)
add_compile_options(-mfloat-abi=hard -mfpu=fpv5-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv5-d16)

add_compile_options(-mcpu=cortex-m7 -mthumb)

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -c -x assembler-with-cpp -gdwarf-4")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections -flto -Wall -fstack-usage --specs=nano.specs -Werror -funsigned-char -fshort-enums -fshort-wchar")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections -Wall -fstack-usage -funsigned-char -fshort-enums -Wno-unused-variable -Wno-unused-function -Wno-unused-value")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections -Wall -fstack-usage -funsigned-char -Wformat=0 -Wno-unused-variable -Wno-unused-function -Wno-unused-value")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -funsigned-char -femit-class-debug-always -fstack-usage")

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g3)
    #    add_compile_options(-O0 -g)
endif ()

include_directories(
        ${CMAKE_SOURCE_DIR}/WOLF/Inc
        ${CMAKE_SOURCE_DIR}/WOLF/Src
        ${CMAKE_SOURCE_DIR}/WOLF/Drivers/STM32H7xx_HAL_Driver/Inc
        ${CMAKE_SOURCE_DIR}/WOLF/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy
        ${CMAKE_SOURCE_DIR}/WOLF/Drivers/CMSIS/Device/ST/STM32H7xx/Include
        ${CMAKE_SOURCE_DIR}/WOLF/Drivers/CMSIS/Include
        ${CMAKE_SOURCE_DIR}/Src/USBDevice
        ${CMAKE_SOURCE_DIR}/Src
        ${CMAKE_SOURCE_DIR}/Src/JPEG
        ${CMAKE_SOURCE_DIR}/WOLF/Middlewares/Third_Party/FatFs/src
        ${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/Core/Include
        ${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Include
        ${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/PrivateInclude
)

add_definitions(-DFRONTPANEL_BIG_V1 -DLCD_RA8875 -DTOUCHPAD_GT911 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG)

file(GLOB_RECURSE SOURCES
        "${CMAKE_SOURCE_DIR}/WOLF/Drivers/*.*"
        "${CMAKE_SOURCE_DIR}/WOLF/Middlewares/*.*"
        "${CMAKE_SOURCE_DIR}/WOLF/Src/*.*"
        "${CMAKE_SOURCE_DIR}/WOLF/cmake/startup_stm32h743vitx.s"
        "${CMAKE_SOURCE_DIR}/WOLF/cmake/crt1.c"
        "${CMAKE_SOURCE_DIR}/WOLF/cmake/syscalls.c"
        "${CMAKE_SOURCE_DIR}/WOLF/cmake/sysmem.c"
        "${CMAKE_SOURCE_DIR}/Src/*.*"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/BasicMathFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/BasicMathFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/BayesFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/BayesFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/CommonTables.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/CommonTablesF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/ComplexMathFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/ComplexMathFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/ControllerFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/DistanceFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/DistanceFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/FastMathFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/FastMathFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/FilteringFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/FilteringFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/InterpolationFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/InterpolationFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/MatrixFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/MatrixFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/QuaternionMathFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/SVMFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/SVMFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/StatisticsFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/StatisticsFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/SupportFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/SupportFunctionsF16.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/TransformFunctions.c"
        "${CMAKE_BINARY_DIR}/_deps/cmsis_5-src/CMSIS/DSP/Source/TransformFunctionsF16.c"
        )

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m7 -mthumb -static -u _printf_float)
add_link_options(-T ${LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

target_link_libraries(${PROJECT_NAME}.elf -Wl,--start-group -lc -lm -lstdc++ -Wl,--end-group)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

#add_custom_command(TARGET ${PROJECT_NAME}.elf PRE_LINK
#        COMMAND ${LcdImageConverter} --help
#        COMMENT "Generate image converter help")

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Generate ${HEX_FILE}
                 Generate ${BIN_FILE}")

add_custom_target("Program-${PROJECT_NAME}"
        DEPENDS ${PROJECT_NAME}.elf
        COMMAND ${STM32CubeProgrammer} -c port=SWD -d ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex -hardRst
        COMMENT "Program ${HEX_FILE}")

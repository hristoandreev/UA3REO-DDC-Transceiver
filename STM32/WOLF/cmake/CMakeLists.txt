cmake_minimum_required(VERSION 3.17)

include(dependencies.cmake)
#include(${CMAKE_SOURCE_DIR}/toolchain.cmake)

set(GENERATED_SOURCE_DIR ${CMAKE_BINARY_DIR}/generated)

message(STATUS "STM32_CUBE_PROGRAMMER_DIR -> " ${STM32_CUBE_PROGRAMMER})
message(STATUS "CMAKE_SOURCE_DIR -> " ${CMAKE_SOURCE_DIR})
message(STATUS "CMAKE_BINARY_DIR -> " ${CMAKE_BINARY_DIR})

# STM32CubeProgrammer
set(STM32CubeProgrammer ${STM32_CUBE_PROGRAMMER}/bin/STM32_Programmer_CLI)
message(STATUS "STM32CubeProgrammer -> " ${STM32CubeProgrammer})

# Image converter
set(ImageConverter ${CMAKE_BINARY_DIR}/_deps/lcd-image-converter-src/lcd-image-converter.exe)
message(STATUS "ImageConverter -> " ${ImageConverter})

# Font converter
set(FontConverter ${CMAKE_SOURCE_DIR}/../Stuff/Fonts/fontconvert.exe)
message(STATUS "FontConverter -> " ${FontConverter})

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Linker script
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/WOLF/cmake/STM32H743VITx_FLASH.ld")

# hardware floating point
add_compile_definitions(ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING;ARM_MATH_LOOPUNROLL)
add_compile_options(-mfloat-abi=hard -mfpu=fpv5-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv5-d16)

# Compiler options
add_compile_options(-mcpu=cortex-m7 -mthumb)

# Compiler flags
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

# Headers directories
include_directories(
        ${CMAKE_SOURCE_DIR}/WOLF/Inc
        ${CMAKE_SOURCE_DIR}/WOLF/Src
        ${CMAKE_SOURCE_DIR}/WOLF/Src/generated/fonts/inc
        ${CMAKE_SOURCE_DIR}/WOLF/Src/generated/images/inc
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
        ${GENERATED_SOURCE_DIR}/fonts
        ${GENERATED_SOURCE_DIR}/images
)

# Definitions
add_definitions(-DFRONTPANEL_BIG_V1 -DLCD_RA8875 -DTOUCHPAD_GT911 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG)

# Source files
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

# Link options
add_link_options(-Wl,--gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m7 -mthumb -static -u _printf_float)
add_link_options(-T ${LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

# Libraries
target_link_libraries(${PROJECT_NAME}.elf -Wl,--start-group -lc -lm -lstdc++ -Wl,--end-group)

# Find all .png and .ttf files from assets directory
file(GLOB_RECURSE IMAGES "${CMAKE_SOURCE_DIR}/WOLF/assets/images/*.png")
file(GLOB_RECURSE FONTS "${CMAKE_SOURCE_DIR}/WOLF/assets/fonts/*.ttf")

# Convert command path to the native command path
cmake_path(CONVERT ${ImageConverter} TO_NATIVE_PATH_LIST ImageConverterNative)
cmake_path(CONVERT ${STM32CubeProgrammer} TO_NATIVE_PATH_LIST STM32CubeProgrammerNative)
cmake_path(CONVERT ${FontConverter} TO_NATIVE_PATH_LIST FontConverterNative)
message(STATUS "ImageConverterNative -> " ${ImageConverterNative})
message(STATUS "STM32CubeProgrammerNative -> " ${STM32CubeProgrammerNative})
message(STATUS "FontConverterNative -> " ${FontConverterNative})

file(MAKE_DIRECTORY ${GENERATED_SOURCE_DIR}/images ${GENERATED_SOURCE_DIR}/fonts)

# Generating the image binaries and adding to build
foreach (IMAGE_PATH ${IMAGES})
    get_filename_component(IMAGE_NAME ${IMAGE_PATH} NAME_WE)
    string(REPLACE "-" "_" IMAGE_NAME "${IMAGE_NAME}")
    string(REPLACE " " "_" IMAGE_NAME "${IMAGE_NAME}")

    add_custom_command(OUTPUT ${GENERATED_SOURCE_DIR}/images/${IMAGE_NAME}.cpp
            DEPENDS
            "${IMAGE_PATH}"
            "${CMAKE_SOURCE_DIR}/WOLF/assets/image.tmpl"
            COMMAND cmd /c "${ImageConverterNative} --mode=convert-image --doc-name=${IMAGE_NAME} --preset-name=\"Color R5G6B5\" --input=${CMAKE_SOURCE_DIR}/WOLF/assets/images/${IMAGE_NAME}.png --output=${GENERATED_SOURCE_DIR}/images/${IMAGE_NAME}.cpp --template=${CMAKE_SOURCE_DIR}/WOLF/assets/image.tmpl"
            COMMENT "Convert ${IMAGE_NAME}.png into ${IMAGE_NAME}.cpp")

    target_sources(${PROJECT_NAME}.elf PUBLIC ${GENERATED_SOURCE_DIR}/images/${IMAGE_NAME}.cpp)
endforeach(IMAGE_PATH)

list(APPEND FONT_SIZES "7" "9" "12" "18" "24" "32" "36")

# Generating the font binaries and adding to build
foreach (FONT_PATH ${FONTS})
    get_filename_component(FONT_NAME ${FONT_PATH} NAME_WE)
    string(REPLACE "-" "_" FONT_NAME "${FONT_NAME}")
    string(REPLACE " " "_" FONT_NAME "${FONT_NAME}")
    list(APPEND font_dependencies "${FONT_PATH}")

    set(font_commands "@echo \#include \"font.h\" > ${GENERATED_SOURCE_DIR}/fonts/${FONT_NAME}.cpp")

    foreach(FONT_SIZE ${FONT_SIZES})
        list(APPEND font_commands "@${FontConverterNative} ${FONT_PATH} ${FONT_SIZE} >> ${GENERATED_SOURCE_DIR}/fonts/${FONT_NAME}.cpp")
        list(APPEND FONTS_LIST "\nextern const GFXfont ${FONT_NAME}${FONT_SIZE}pt7b")
    endforeach()

    string(REPLACE ";" "\r\n" font_commands_txt "${font_commands}")
    file(GENERATE OUTPUT "generate_fonts_${FONT_NAME}.cmd" CONTENT "${font_commands_txt}")

    add_custom_command(OUTPUT ${GENERATED_SOURCE_DIR}/fonts/${FONT_NAME}.cpp
            DEPENDS
            ${font_dependencies}
            COMMAND
            cmd /c "generate_fonts_${FONT_NAME}.cmd"
            COMMENT "Convert ${FONT_NAME}.ttf into ${FONT_NAME}.cpp")

    target_sources(${PROJECT_NAME}.elf PUBLIC  ${GENERATED_SOURCE_DIR}/fonts/${FONT_NAME}.cpp)
endforeach(FONT_PATH)

list(APPEND FONTS_LIST "")  # Insert last ";"
configure_file(
        ${CMAKE_SOURCE_DIR}/WOLF/assets/font.h.in
        ${GENERATED_SOURCE_DIR}/fonts/font.h
        @ONLY
)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

# Generate .hex and .bin from .elf
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Generate ${HEX_FILE}
                 Generate ${BIN_FILE}")

# Programming embedded and external flash images, using STM32CubeProgrammer tool
add_custom_target("Program-${PROJECT_NAME}"
        DEPENDS ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex
        COMMAND ${STM32CubeProgrammerNative} -c port=SWD -d ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex -hardRst
        COMMENT "Programming ${HEX_FILE}")

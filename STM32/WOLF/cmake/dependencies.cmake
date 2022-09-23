cmake_minimum_required(VERSION 3.14)

include(FetchContent)

######################################## CMSIS-5 ###################################################
FetchContent_Declare(
    cmsis_5
    URL https://github.com/ARM-software/CMSIS_5/archive/refs/heads/master.zip
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_MakeAvailable(cmsis_5)
###################################### END CMSIS-5 #################################################

################################## lcd-image-converter #############################################
FetchContent_Declare(
    lcd-image-converter
    URL https://sourceforge.net/projects/lcd-image-converter/files/latest/download?use_mirror=autoselect
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_MakeAvailable(lcd-image-converter)
############################## END lcd-image-converter #############################################
project(PhononWaveOut)

cmake_minimum_required(VERSION 2.6.2 FATAL_ERROR)

find_package(Phonon REQUIRED)

set(PHONON_WAVEOUT_LIB_MAJOR_VERSION "4")
set(PHONON_WAVEOUT_LIB_MINOR_VERSION "4")
set(PHONON_WAVEOUT_LIB_PATCH_VERSION "3")
set(PHONON_WAVEOUT_LIB_VERSION "${PHONON_LIB_MAJOR_VERSION}.4.0")

add_definitions(${QT_DEFINITIONS})
include_directories(${PHONON_INCLUDES} ${QT_INCLUDES})

# FIXME: apparently there has never been code to compile the source files?!
# add_subdirectory(waveout)

macro_display_feature_log()

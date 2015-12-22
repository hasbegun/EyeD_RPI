cmake_minimum_required(VERSION 3.3)
project(EyeD_RPI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR}/../../)

#OpenCV required
FIND_PACKAGE(OpenCV REQUIRED)
IF (${OpenCV_VERSION} VERSION_LESS 2.4.11)
    MESSAGE(FATAL_ERROR "OpenCV version is not compatible: ${OpenCV_VERSION}. EyeD_RPI requires at least OpenCV v2.4.1")
ENDIF()

include_directories(${PROJECT_ROOT}/BiometricLib/Iris)
include_directories(${PROJECT_ROOT}/BiometricLib/Masek)
include_directories(${PROJECT_ROOT}/BiometricLib/Face)

set(SOURCE_FILES src/main.cpp
        src/detectObject.cpp
        src/preprocessFace.cpp
        src/recognition.cpp
        src/ImageUtils_0.7.cpp
        )

add_executable(EyeD_RPI ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/../../BiometricLib/build/libBiometricLib.a)


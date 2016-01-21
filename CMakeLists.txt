cmake_minimum_required(VERSION 3.3)
project(EyeD_RPI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "debug")
set(PROJECT_BASE_PATH ${CMAKE_SOURCE_DIR}/../../)

#OpenCV required
find_package(OpenCV REQUIRED)
IF (${OpenCV_VERSION} VERSION_LESS 2.4.11)
    MESSAGE(FATAL_ERROR "OpenCV version is not compatible: ${OpenCV_VERSION}. EyeD_RPI requires at least OpenCV v2.4.1")
ENDIF()

#include_directories(${PROJECT_BASE_PATH}BiometricLib/Iris)
#include_directories(${PROJECT_BASE_PATH}BiometricLib/Masek)
#include_directories(${PROJECT_BASE_PATH}BiometricLib/Face)

include_directories(${PROJECT_BASE_PATH}BiometricLib/src)

set(SOURCE_FILES src/main.cpp
#        src/detectObject.cpp
#        src/preprocessFace.cpp
#        src/recognition.cpp
#        src/ImageUtils_0.7.cpp
)

set(LIBS ${OpenCV_LIBS}
         ${PROJECT_BASE_PATH}BiometricLib/build/libFace.a
         ${PROJECT_BASE_PATH}BiometricLib/build/libIris.a
)

message(status ${PROJECT_BASE_PATH}BiometricLib/build)

add_executable(EyeD_RPI ${SOURCE_FILES})
target_link_libraries(EyeD_RPI ${LIBS})

install(TARGETS EyeD_RPI DESTINATION bin)

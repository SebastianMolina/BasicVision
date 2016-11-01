cmake_minimum_required(VERSION 3.5)
project(BasicVision)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if (${CYGWIN})
    set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/libs/opencv-3.0.0-win-shared/share/OpenCV)
endif (${CYGWIN})
find_package(OpenCV 3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB SOURCES "util/*.cpp" "include/*.h")
add_library(VisionLib ${SOURCES})

set(IMAGE_LIBS ${OpenCV_LIBS} ${OpenCL_LIBS})

include_directories(include)

set(SOURCE_FILES src/main.cpp util/VisionFiltering.cpp include/VisionFiltering.h util/Print2Text.cpp include/Print2Text.h util/BuoyFinder.cpp util/NinjaFinder.cpp include/BuoyFinder.h include/NinjaFinder.h util/CamTracker.cpp include/CamTracker.h)
add_executable(BasicVision ${SOURCE_FILES})

target_link_libraries(BasicVision ${IMAGE_LIBS} VisionLib)
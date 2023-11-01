cmake_minimum_required(VERSION 3.12)
project(VideoFrameCapture)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

add_executable(VideoFrameCapture main.cpp)
target_link_libraries(VideoFrameCapture ${OpenCV_LIBS})
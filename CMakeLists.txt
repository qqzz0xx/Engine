cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)	
project (ZZEngine)

include_directories("${PROJECT_SOURCE_DIR}/Common")
include_directories("${PROJECT_SOURCE_DIR}/Interface")

add_subdirectory(Common)
add_executable(App MainApp.cpp)
target_link_libraries(App Common)

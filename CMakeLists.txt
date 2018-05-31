cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)	
project (ZZEngine)

include_directories("${PROJECT_SOURCE_DIR}/Core")

add_subdirectory(Core)

file (GLOB Sources *.cpp *.cc)
file (GLOB Heads *.hpp *.h)

add_executable(App ${Heads} ${Sources})
target_link_libraries(App Core)
target_link_libraries(App D2D1.lib ole32.lib)

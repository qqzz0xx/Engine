cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project (ZZEngine)

set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)	

find_package(OpenGL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/External/assimp/include)
include_directories("${PROJECT_SOURCE_DIR}/Core")
include_directories("${PROJECT_SOURCE_DIR}/External/glad/include")
include_directories("${PROJECT_SOURCE_DIR}/External/glm")

link_directories(${PROJECT_SOURCE_DIR}/External/assimp/lib)

add_subdirectory(Core)

file (GLOB Sources *.cpp *.cc)
file (GLOB Heads *.hpp *.h)

add_executable(App ${Heads} ${Sources} 
	"${PROJECT_SOURCE_DIR}/External/glad/src/glad.c"
	"${PROJECT_SOURCE_DIR}/External/glad/src/glad_wgl.c")

target_link_libraries(App Core)
target_link_libraries(App D2D1.lib ole32.lib d3d11.lib)
target_link_libraries(App ${OPENGL_LIBRARIES})
target_link_libraries(App assimp-vc140-mt.lib IrrXML.lib zlibstatic.lib)
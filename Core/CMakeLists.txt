file (GLOB Sources *.cpp *.cc)
file (GLOB Heads *.hpp *.h)

add_library(Core ${Sources} ${Heads})
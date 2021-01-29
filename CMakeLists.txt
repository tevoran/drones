cmake_minimum_required(VERSION 3.18)
project("drones")



#kosmonaut engine include
find_library(MATHS m)
find_library(SDL2 SDL2)
find_library(NNG nng)
find_library(PTHREAD pthread)
find_library(GLEW GLEW)
find_library(GL GL)

include_directories(kosmonaut/)
link_directories("../drones/")
find_library(kosmonaut kosmonaut)
#set_target_properties(KOSMONAUT_LIB PROPERTIES LINKER_LANGUAGE C)

set(CMAKE_C_FLAGS "")

#creating drones game
file(GLOB_RECURSE drones_SRC src/*.c)
add_executable(drones ${drones_SRC})

target_link_libraries(drones PRIVATE kosmonaut)
target_link_libraries(drones LINK_PRIVATE "${MATHS}")
target_link_libraries(drones LINK_PRIVATE "${SDL2}")
target_link_libraries(drones LINK_PRIVATE "${NNG}")
target_link_libraries(drones LINK_PRIVATE "${PTHREAD}")
target_link_libraries(drones LINK_PRIVATE "${GLEW}")
target_link_libraries(drones LINK_PRIVATE "${GL}")

file(COPY build/drones DESTINATION ../)
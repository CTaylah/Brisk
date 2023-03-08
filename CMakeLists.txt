
cmake_minimum_required(VERSION 3.2)
project(Brisk)




#add soruce files
file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/external/*.c
    ${CMAKE_SOURCE_DIR}/external/*.cpp
    )

#Add header files
file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.hpp
    )
    
#add .lib files
#link_directories(${CMAKE_SOURCE_DIR}/dep/lib)

set(libraryPath ${CMAKE_SOURCE_DIR}/dep/lib)

#define the executuble
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${libraryPath}/assimp/assimp-vc143-mt.lib)
target_link_libraries(${PROJECT_NAME} ${libraryPath}/glfw/glfw3.lib)

include_directories(${CMAKE_SOURCE_DIR}/dep/include)
include_directories(${CMAKE_SOURCE_DIR}/external)
include_directories(${CMAKE_SOURCE_DIR}/src/)

add_subdirectory(${CMAKE_SOURCE_DIR}/external)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
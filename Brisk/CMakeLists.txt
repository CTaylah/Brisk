

#add soruce files
file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib/*.cpp
    )

#Add header files
file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
    )
    

set(libraryPath ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib)

#define the executuble
#add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${libraryPath}/assimp/assimp-vc143-mt.lib)
target_link_libraries(${PROJECT_NAME} ${libraryPath}/glfw/glfw3.lib)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

# include_directories(${CMAKE_SOURCE_DIR}/external)
# include_directories(${CMAKE_SOURCE_DIR}/src/)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
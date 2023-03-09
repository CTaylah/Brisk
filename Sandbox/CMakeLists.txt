
file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    )

#Add header files
file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
    )
 
include_directories(${CMAKE_SOURCE_DIR}/Brisk/src)
include_directories(${CMAKE_SOURCE_DIR}/Brisk/vendor/include)

add_executable("Sandbox" ${HEADER_FILES} ${SOURCE_FILES})
link_directories(${CMAKE_SOURCE_DIR}/build/Brisk/Debug/)
target_link_libraries("Sandbox" ${CMAKE_SOURCE_DIR}/Brisk/vendor/lib/glfw/glfw3.lib) 
target_link_libraries("Sandbox" ${CMAKE_SOURCE_DIR}/Brisk/vendor/lib/assimp/assimp-vc143-mt.lib)
target_link_libraries("Sandbox" ${CMAKE_SOURCE_DIR}/bin/Debug/Brisk.lib)

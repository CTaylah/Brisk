include_directories("../dep/include/")
include_directories("../external/")

add_subdirectory(${CMAKE_SOURCE_DIR}/src/Renderer)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Core)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Util)
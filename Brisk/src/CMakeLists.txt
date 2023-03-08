# include_directories("../dep/include/")
# include_directories("../external/")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Renderer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Core)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Util)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Asset)
## Library
add_library(unordered_map INTERFACE)

## Headers
target_sources(unordered_map
    INTERFACE
        unordered_map.hpp
)

## Define module
target_include_directories(unordered_map
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Library
add_library(linked_list INTERFACE)

## Headers
target_sources(linked_list
    INTERFACE
        linked_list.hpp
)

## Define module
target_include_directories(linked_list
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

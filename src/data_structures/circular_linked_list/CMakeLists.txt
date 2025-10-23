## Library
add_library(circular_linked_list INTERFACE)

## Headers
target_sources(circular_linked_list
    INTERFACE
        circular_linked_list.hpp
)

## Define module
target_include_directories(circular_linked_list
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

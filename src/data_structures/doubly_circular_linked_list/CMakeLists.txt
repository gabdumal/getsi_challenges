## Library
add_library(doubly_circular_linked_list INTERFACE)

## Headers
target_sources(doubly_circular_linked_list
    INTERFACE
        doubly_circular_linked_list.hpp
)

## Define module
target_include_directories(doubly_circular_linked_list
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Library
add_library(stack INTERFACE)

## Headers
target_sources(stack
    INTERFACE
        stack.hpp
)

## Define module
target_include_directories(stack
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Library
add_library(queue INTERFACE)

## Headers
target_sources(queue
    INTERFACE
        queue.hpp
)

## Define module
target_include_directories(queue
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

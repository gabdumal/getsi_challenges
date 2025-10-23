## Library
add_library(preferential_queues)

## Sources
target_sources(preferential_queues
    PUBLIC
        algorithm.hpp
    PRIVATE
        algorithm.cpp
)

## Define module
target_include_directories(preferential_queues
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(preferential_queues
    PRIVATE
        data_structures
        tester
)

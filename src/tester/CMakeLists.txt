## Library
add_library(tester)

## Sources
target_sources(tester
    PUBLIC
        tester.hpp
    PRIVATE
        tester.cpp
)

## Define module
target_include_directories(tester
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

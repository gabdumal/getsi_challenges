## Library
add_library(cinephiles_on_vacations)

## Sources
target_sources(cinephiles_on_vacations
    PUBLIC
        algorithm.hpp
    PRIVATE
        algorithm.cpp
)

## Define module
target_include_directories(cinephiles_on_vacations
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(cinephiles_on_vacations
    PRIVATE
        data_structures
        tester
)

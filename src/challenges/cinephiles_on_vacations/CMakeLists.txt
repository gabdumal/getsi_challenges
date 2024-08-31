# Project
add_library(cinephiles_on_vacations)

# Sources
target_sources(cinephiles_on_vacations
    PUBLIC
        algorithm.hpp
    PRIVATE
        algorithm.cpp
)


# Include self
target_include_directories(cinephiles_on_vacations
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

# Linking libraries
target_link_libraries(cinephiles_on_vacations
    PRIVATE
        tester
        data_structures
)

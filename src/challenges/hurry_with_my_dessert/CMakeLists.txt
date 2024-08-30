# Project
add_library(hurry_with_my_dessert)

# Sources
target_sources(hurry_with_my_dessert
    PUBLIC
        algorithm.hpp
    PRIVATE
        algorithm.cpp
)


# Include self
target_include_directories(hurry_with_my_dessert
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

# Linking libraries
target_link_libraries(hurry_with_my_dessert
    PRIVATE
        tester
)

# Project
add_library(tester)

# Sources
target_sources(tester
    PUBLIC
        tester.hpp
    PRIVATE
        tester.cpp
)


# Include self
target_include_directories(tester
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

# Linking libraries
target_link_libraries(tester
    PRIVATE
)

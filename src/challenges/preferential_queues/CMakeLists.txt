# Project
add_library(preferential_queues)

# Sources
target_sources(preferential_queues
    PUBLIC
        algorithm.hpp
    PRIVATE
        algorithm.cpp
)


# Include self
target_include_directories(preferential_queues
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

# Linking libraries
target_link_libraries(preferential_queues
    PRIVATE
        tester
        data_structures
)

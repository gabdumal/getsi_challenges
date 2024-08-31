# Sources
target_sources(data_structures
    PUBLIC
        queue.hpp
)

# Include self
target_include_directories(data_structures
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

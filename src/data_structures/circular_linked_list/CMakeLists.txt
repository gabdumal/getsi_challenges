# Sources
target_sources(data_structures
    PUBLIC
        circular_linked_list.hpp
    PRIVATE
        circular_linked_list.cpp
)

# Include self
target_include_directories(data_structures
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

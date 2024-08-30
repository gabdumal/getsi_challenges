# Project
add_library(data_structures)

# Include self
target_include_directories(tester
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

# Linking libraries
target_link_libraries(tester
    PRIVATE
)

# Directories
add_subdirectory(linked_list)
add_subdirectory(circular_linked_list)
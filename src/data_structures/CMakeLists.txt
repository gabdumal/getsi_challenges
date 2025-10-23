## Library
add_library(data_structures INTERFACE)

## Directories
add_subdirectory(circular_linked_list)
add_subdirectory(doubly_circular_linked_list)
add_subdirectory(linked_list)
add_subdirectory(queue)
add_subdirectory(stack)
add_subdirectory(unordered_map)

## Linking libraries
target_link_libraries(data_structures
    INTERFACE
        circular_linked_list
        doubly_circular_linked_list
        linked_list
        queue
        stack
        unordered_map
)

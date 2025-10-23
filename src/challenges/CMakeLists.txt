## Library
add_library(challenges)

## Directories
add_subdirectory(cinephiles_on_vacations)
add_subdirectory(preferential_queues)

## Linking libraries
target_link_libraries(challenges
    PRIVATE
        cinephiles_on_vacations
        preferential_queues
)

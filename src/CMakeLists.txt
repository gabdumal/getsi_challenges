# Executables
add_executable(getsi_challenges
    main.cpp
)

# Include directories
target_include_directories(getsi_challenges
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

# Linking libraries
target_link_libraries(getsi_challenges
    PRIVATE
        console_colors
        hurry_with_my_dessert
)

# Directories
add_subdirectory(hurry_with_my_dessert)
add_subdirectory(preferential_queues)
add_subdirectory(cinephiles_on_vacations)

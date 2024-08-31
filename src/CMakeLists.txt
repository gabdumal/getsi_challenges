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
        tester
        data_structures
        hurry_with_my_dessert
        preferential_queues
        cinephiles_on_vacations
)

# Directories
add_subdirectory(challenges)
add_subdirectory(tester)
add_subdirectory(data_structures)

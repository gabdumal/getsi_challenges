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
        hurry_with_my_dessert
)

# Directories
add_subdirectory(challenges)
add_subdirectory(tester)

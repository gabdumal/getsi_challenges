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
)

# Directories
add_subdirectory(preferential_queues)

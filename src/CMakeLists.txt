## Executable
add_executable(getsi_challenges
    main.cpp
)

## Directories
add_subdirectory(data_structures)
add_subdirectory(challenges)
add_subdirectory(tester)

## Linking libraries
target_link_libraries(getsi_challenges
    PRIVATE
        challenges
        data_structures
        tester
)

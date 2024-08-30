# Project
add_library(console_colors console_colors.cpp)

# Include self
target_include_directories(console_colors
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

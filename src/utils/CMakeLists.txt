add_library(utils STATIC
    getrandom.cpp
    timepoint.cpp
)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

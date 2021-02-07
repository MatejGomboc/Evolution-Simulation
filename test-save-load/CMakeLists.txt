cmake_minimum_required(VERSION 3.0)

project(test-save-load LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(test-save-load
    main.cpp
)

target_include_directories(test-save-load PRIVATE
    ${CMAKE_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}/common/instructions
)

target_link_libraries(test-save-load PRIVATE
    common
)

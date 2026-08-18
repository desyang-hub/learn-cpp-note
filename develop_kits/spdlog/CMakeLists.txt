cmake_minimum_required(VERSION 3.21)

project(spdlog_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# 添加logger
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/setup_spdlog.cmake)

add_executable(example
    example.cpp
)

target_link_libraries(example
    PRIVATE
    logger
)
cmake_minimum_required(VERSION 3.18)

project(matching-engine C CXX)

set(PROJECT_VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(src)
add_subdirectory(lib)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

cmake_minimum_required(VERSION 3.10)

project(thread_pool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/thread_pool SRCLIST_THREAD_POOL)
add_library(thread_pool SHARED ${SRCLIST_THREAD_POOL})

add_executable(test test.cpp)
target_link_libraries(test
    thread_pool
    pthread 
)


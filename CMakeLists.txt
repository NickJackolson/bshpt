cmake_minimum_required(VERSION 3.10)

project(Battleship)

set(SOURCES
    test.cpp
    sources/ship.cpp
    sources/board.cpp
)

# Add an executable with the above sources
add_executable(test ${SOURCES})

target_include_directories(test
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)
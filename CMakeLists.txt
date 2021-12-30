cmake_minimum_required(VERSION 3.10)

project(Battleship)

set(T_SOURCES
    test.cpp
    sources/ship.cpp
    sources/board.cpp
)

set(SOURCES
    main.cpp
    sources/ship.cpp
    sources/board.cpp
    sources/game.cpp
)

# Add an executable with the above sources
add_executable(test ${T_SOURCES})
add_executable(app ${SOURCES})

target_include_directories(test
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(app
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
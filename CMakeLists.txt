cmake_minimum_required(VERSION 3.10)
project(WheelOfFortune LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    game.cpp
    user.cpp
    puzzle.cpp
    WordHandler.cpp
    wheeloutcome.cpp
    wheel.cpp
    reward.cpp
    penalty.cpp
)

# executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# include current directory for headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY puzzles DESTINATION share/${PROJECT_NAME})
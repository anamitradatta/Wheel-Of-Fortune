cmake_minimum_required(VERSION 3.10)
project(WheelOfFortune LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

add_subdirectory(game)
add_subdirectory(user)
add_subdirectory(wheel)
add_subdirectory(puzzles)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY puzzles DESTINATION share/${PROJECT_NAME})
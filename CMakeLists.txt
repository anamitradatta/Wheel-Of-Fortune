cmake_minimum_required(VERSION 3.10)
project(WheelOfFortune LANGUAGES CXX)

# Require C++20 for modern features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# collect source files (search only project sources and avoid any generated build files)
#
# When a build directory lives inside the source tree (e.g. `./build`), the
# recursive glob will pick up CMake's own generated files such as
# CMakeFiles/.../CMakeCXXCompilerId.cpp which contain a second `main()` and
# lead to linker errors.  We filter them out explicitly here as a defensive
# measure.  Better yet, create an out‑of‑source build (the default in the
# README instructions below).
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# remove anything under a "build" subdirectory or the CMakeFiles tree
list(FILTER SOURCES EXCLUDE REGEX ".*/build/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/CMakeFiles/.*")

# executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# include current directory for headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# link threading library (std::thread)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# ensure puzzle data accompanies the binary
add_custom_target(copy_puzzles ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/puzzles
            ${CMAKE_CURRENT_BINARY_DIR}/puzzles
    COMMENT "Copy puzzle files to binary output"
)
add_dependencies(${PROJECT_NAME} copy_puzzles)

# installation (optional)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY puzzles DESTINATION share/${PROJECT_NAME})

if(NOT TARGET ${PROJECT_NAME})
    message(FATAL_ERROR "Parent target ${PROJECT_NAME} not found. Ensure add_executable(${PROJECT_NAME}) is in the top-level CMakeLists before add_subdirectory(user).")
endif()

target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/puzzle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WordHandler.cpp
)

# make sure the parent target can see the headers in this directory
# (the top‑level CMakeLists also adds the path, so this is optional)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

cmake_minimum_required(VERSION 3.16)
project(WordArrayProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(tests)

# Add the main program
add_executable(main
    Word.cpp
    ArrayOfWords.cpp
    dialog.cpp
)











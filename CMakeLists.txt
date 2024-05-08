# Root CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(TerminalGames)

# Add main.cpp
add_executable(TerminalGames Games/main.cpp)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Games)

# Add subdirectory for Hangman game
add_subdirectory(Games/Hangman)

# Link HangmanLib to TerminalGames executable
target_link_libraries(TerminalGames PRIVATE HangmanLib)

configure_file(${CMAKE_SOURCE_DIR}/data/dictionary.txt ${CMAKE_CURRENT_BINARY_DIR}/dictionary.txt COPYONLY)



cmake_minimum_required(VERSION 3.14)

project(ToDoProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# --- 1. Основна програма ---
add_executable(ToDoApp
    src/main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

# --- 2. Налаштування тестів ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Примушуємо GTest працювати з бібліотеками MSVC (вирішує помилку MTd vs MDd)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- 3. Тестова програма ---
add_executable(ToDoTests
    tests/test_main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

target_include_directories(ToDoTests PRIVATE include)
target_link_libraries(ToDoTests gtest_main)

include(GoogleTest)
gtest_discover_tests(ToDoTests)
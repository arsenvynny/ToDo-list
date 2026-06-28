cmake_minimum_required(VERSION 3.14)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

project(ToDoProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# --- Пошук та завантаження зовнішніх бібліотек ---
find_package(TgBot CONFIG REQUIRED)

include(FetchContent)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(json)

# --- 1. Основна програма ---
add_executable(ToDoApp
    src/main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

target_link_libraries(ToDoApp PRIVATE nlohmann_json::nlohmann_json TgBot::TgBot)
target_compile_options(ToDoApp PRIVATE /utf-8)

# --- 2. Налаштування тестів ---
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(ToDoTests
    tests/test_main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

target_include_directories(ToDoTests PRIVATE include)
target_link_libraries(ToDoTests gtest_main nlohmann_json::nlohmann_json)

include(GoogleTest)
gtest_discover_tests(ToDoTests)
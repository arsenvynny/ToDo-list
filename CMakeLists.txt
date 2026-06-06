cmake_minimum_required(VERSION 3.14)

# Назва нашого проекту
project(ToDoProject VERSION 1.0 LANGUAGES CXX)

# Використовуємо сучасний стандарт C++ (мінімум 17-й, він ідеально підійде для роботи з файлами)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Вказуємо, де лежать наші заголовкові файли (.h)
include_directories(include)

# Створюємо виконуваний файл з наших вихідних файлів
add_executable(ToDoApp
    src/main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)
To-Do List Telegram Bot
This is a C++ project for a to-do list with a Telegram bot. I creating this for myself. The goal is to organize the routine

The project is still in development. The task classes and task manager are in the code, but they are not fully connected to the Telegram bot yet.
Features
- Create different task types in the code: daily, weekly, and monthly tasks.
- Set task priority: high, medium, or low.
- Store a task description and its completion status.
- Sort tasks by priority.
- Convert task data to JSON format.
- Start a Telegram bot and receive messages.
- Use the /start command to get a welcome message.
- Send a normal message to the bot and receive the same text back.
Technologies
- C++17 — main programming language.
- CMake — project build system.
- TgBot — library for the Telegram Bot API.
- nlohmann/json — library for working with JSON data.
- GoogleTest — test framework.

Requirements
Before you start, you need:
- A C++17 compiler.
- CMake.
- Git.
- vcpkg to install the TgBot library.
- A Telegram bot token.

Setup
1. Install TgBot with vcpkg
Install vcpkg by following its official instructions. Then install the tgbot-cpp package:
vcpkg install tgbot-cpp
2. Configure the project
Open a terminal in the project folder. Use CMake and provide the path to the vcpkg toolchain file.

Example for Windows, if vcpkg is installed in C:\tools\vcpkg:
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
If vcpkg is installed in another folder, change the path in the command.
3. Add your Telegram bot token
Create a file named .env in the project folder. Although the file is named .env, the current code reads it as JSON. Use this format:
{
  "BOT_TOKEN": "YOUR_TELEGRAM_BOT_TOKEN"
}
Replace YOUR_TELEGRAM_BOT_TOKEN with your token. Keep this file private and do not upload your real token to a public repository.
4. Run the bot
Run the ToDoApp program created by CMake. The exact path depends on your compiler and build settings. Start the program from the project folder so it can find the .env file.

Open Telegram and send /start to your bot. At the moment, the bot sends a welcome message. Other text messages are repeated back to you.

Development Notes
Some parts of the project still need work before the project can build and run on every computer:
- include/UserStore.h contains a file path from the original developer's computer. This should be replaced with a relative include, such as #include "TaskManager.h".
- The test file calls saveToFile() and loadFromFile(), but these methods are not defined in ToDoList yet.
- The current Telegram bot does not yet provide commands to create, show, sort, or save tasks.
- The CMake settings include /utf-8, which is a compiler option for Microsoft Visual C++ and may need a change for other compilers.
These are known development tasks, not features that are already complete.

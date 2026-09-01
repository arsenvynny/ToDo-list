#include <iostream>
#include <tgbot/tgbot.h>
#include <unordered_map>

#ifdef _WIN32
#include <windows.h>
#endif

#include "TaskManager.h"

std::string get_token()
{
    std::ifstream f(".env");
    nlohmann::json parsedJson;
    std::string token;

    if(f.is_open())
    {
        f >> parsedJson;

        token = parsedJson["BOT_TOKEN"];
    }
    return token;
}
int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif 

    std::unordered_map<std::int64_t, ToDoList> tasks;


    TgBot::Bot bot(get_token());

    bot.getEvents().onCommand("start", [&bot, &tasks](TgBot::Message::Ptr message) {

      

       bot.getApi().sendMessage(message->chat->id, "Привіт!\n твої завдання на сьогодні:\n");
    });

    // Обробка будь-якого іншого текстового повідомлення
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        // Якщо це команда, ми її ігноруємо (вона обробляється вище)
        if (StringTools::startsWith(message->text, "/")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Ти написав: " + message->text);
    });

    // Запуск нескінченного циклу прослуховування сервера Telegram (Long Poll)
    try {
        std::cout << "Бот успішно запущений! Ім'я: " << bot.getApi().getMe()->username << std::endl;
        TgBot::TgLongPoll longPoll(bot);
        
        while (true) {
            std::cout << "Очікування нових повідомлень..." << std::endl;
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        std::cerr << "Помилка Telegram API: " << e.what() << std::endl;
    }

    return 0;
}
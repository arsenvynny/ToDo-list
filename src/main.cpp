#include <iostream>
#include <tgbot/tgbot.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "TaskManager.h"

int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif 

    ToDoList manager;

    // Встав сюди токен, який тобі видав BotFather
    TgBot::Bot bot("8991577176:AAEFv7PmZpP1Oxd1mXdtIPjSsWz-yA_Mn-g");

    bot.getEvents().onCommand("start", [&bot, &manager](TgBot::Message::Ptr message) {

        manager.loadFromFile("tasks.json");
        std::string response;

        if (manager.getcount() == 0)
            bot.getApi().sendMessage(message->chat->id, "У тебе на сьогодні немає роботи. Можеш відпочити!");
        
        else
        {
            bot.getApi().sendMessage(message->chat->id, "Привіт!\n твої завдання на сьогодні:\n");
            for (const auto &i : manager.getTasks())
                i->show();
        }
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
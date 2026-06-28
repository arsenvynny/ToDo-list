#include <iostream>
#include <tgbot/tgbot.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif 
    // Встав сюди токен, який тобі видав BotFather
    TgBot::Bot bot("8991577176:AAEFv7PmZpP1Oxd1mXdtIPjSsWz-yA_Mn-g");

    // Обробка команди /start
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Привіт! Я твій особистий Event Manager. Система готова до роботи!");
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
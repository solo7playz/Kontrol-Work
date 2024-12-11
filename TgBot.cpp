#include "TgBot.h"

//TgBot1::TgBot1(string token, database db/*, shared_ptr<Database> user*/) :Token(Token), db(db) { /*user = make_shared<Database>(db, Token);*/ }
TgBot1::TgBot1(string Token, database db) : Token(Token), db(db) {}

int TgBot1::JustBot() {
    Bot bot(Token);
    bot.getEvents().onCommand("start", [&](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi", true, 0, nullptr);
        std::cout << "User " << message->chat->id << " started bot\n";
        });

    bot.getEvents().onAnyMessage([&](Message::Ptr message) {
        if (StringTools::startsWith(message->text, "/start")) {
            bot.getApi().deleteMessage(message->chat->id, message->messageId);
            return;
        }
        });
    return 0;
}
database TgBot1::get_db() { return db; }
int TgBot1::Test() {
    Database db1(get_db());
    Bot bot(Token);
    string question2;
    string answer2;
    //db1.get_db() << "select question2 from users ORDER BY question2 DESC LIMIT 1;" >> question2; 
    ////u8string q(question2.begin(), question2.end());
    ////string fullquestion2(question2.begin(), question2.end());
    //db1.get_db() << "select question2answer from users ORDER BY question2answer Desc Limit 1;" >> answer2;
    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> row0;
    InlineKeyboardButton::Ptr checkButton(new InlineKeyboardButton);
    checkButton->text = "No";
    checkButton->callbackData = "No";
    row0.push_back(checkButton);
    keyboard->inlineKeyboard.push_back(row0);
    vector<InlineKeyboardButton::Ptr> row1;
    InlineKeyboardButton::Ptr checkButton1(new InlineKeyboardButton);
    checkButton1->text = "Yes";
    checkButton1->callbackData = "Yes";
    row1.push_back(checkButton1);
    keyboard->inlineKeyboard.push_back(row1);

    //InlineKeyboardMarkup::Ptr keyboardMenu(new InlineKeyboardMarkup);
    //vector<InlineKeyboardButton::Ptr> row2;
    //InlineKeyboardButton::Ptr checkButton2(new InlineKeyboardButton);
    //checkButton2->text = db << "select question1answer from users ORDER BY question1answer DESC LIMIT 1;";
    //checkButton2->callbackData = db << "select question1answer from users ORDER BY question1answer DESC LIMIT 1;";
    //row2.push_back(checkButton2);
    //keyboardMenu->inlineKeyboard.push_back(row2);
    //vector<InlineKeyboardButton::Ptr> row3;
    //InlineKeyboardButton::Ptr checkButton3(new InlineKeyboardButton);
    //checkButton3->text = "Black hole";
    //checkButton3->callbackData = "Black hole";
    //row3.push_back(checkButton3);
    //keyboardMenu->inlineKeyboard.push_back(row3);

    bot.getEvents().onCommand("testik", [&](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "hg", true, true, keyboard, "Markdown");
        });
    bot.getEvents().onCommand("Yes", [&](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Excelent");
        });
    bot.getEvents().onCommand("No", [&](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "loser");
        });
    try {
        cout << "Bot username: %s\n" << bot.getApi().getMe()->username.c_str() << endl;
        bot.getApi().deleteWebhook();

        TgLongPoll longPoll(bot);
        while (true) {
            cout << "Long poll started\n";
            longPoll.start();
        }
    }
    catch (exception& e) {
        cout << "error: %s\n" << e.what();
    }
    return 0;
}

void TgBot1::Catch(const sqlite::sqlite_exception& e) {
    Bot bot(Token);
    bot.getEvents().onAnyMessage([&](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, e.what());
        });
}
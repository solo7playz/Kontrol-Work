#include "TgBot.h"
#include "Database.h"

int main() {
	system("chcp 1251");
	string Token = "7694953212:AAHvoK0HXmU55OQ1k_c6FjDZXkmc4U_n54k";
	database db("users.db");
	TgBot1 bot1(Token, db);
	Database dbCli(db);
	bot1.JustBot();
	bot1.Test();
	// data base don't workin' because sqlite-modern-cpp library support only UTF16 unicode. I was tested curl, wstring, system(chcp ***) 
	// and encoding by telegramm bot, but sqlite-modern-cpp worse than sqlite3 
}
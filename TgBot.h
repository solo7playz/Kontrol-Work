#pragma once
#include "Database.h"

class TgBot1 {
	string Token;
	database db;
public:
	TgBot1(string token, database db);
	database get_db();
	int JustBot();
	void SendMessage1();
	void AddQuestion();
	void Result();
	int Test();
	void Catch(const sqlite::sqlite_exception& e);
};
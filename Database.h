#pragma once
#include <iostream>
#include <string>
#include <sqlite_modern_cpp.h>
#include <tgbot/tgbot.h>
#include <algorithm>
//#include "TgBot.h"

using namespace std;
using namespace sqlite;
using namespace TgBot;

class Database {
	database db;
	//TgBot1 botik;
public:
	//Database(database database, TgBot1 botik);
	Database(database database);
	database get_db();
};
#include "Database.h"

//Database::Database(database database, TgBot1 botik) :db(database), botik(botik) {
//    try {
//        db << "CREATE TABLE IF NOT EXISTS users ("
//            "id INTEGER PRIMARY KEY,"
//            "question1 TEXT,"
//            "question2 TEXT,"
//            "question3 TEXT,"
//            "question4 TEXT,"
//            "question5 TEXT,"
//            "question1answer TEXT,"
//            "question2answer TEXT,"
//            "question3answer TEXT,"
//            "question4answer TEXT,"
//            "question5answer TEXT,"
//            ");";
//        db << "INSERT INTO users( question1, question2, question3, question4, question5, question1answer, question2answer, question3answer, question4answer, question5answer) VALUES ( ?, ?, ?, ?, ?);" << "����� ��������������� ��������� ����� ����� ������ ��� �����, ����� ������������ � �����������?" << "������ ��, ��� ���� ��������� ���������� � ���������� ���������?" << "������ ��������� ��������� � ���� ��������� ����������?" << "���������� �� � ���������� ������� �����������?" << "hi?" << "Aliens" << "Yes" << "Because" << "No, it's bread" << "Hello, world";
//    }
//    catch (sqlite_exception& e) { botik.Catch(e); }
//}
Database::Database(database database) : db(database) {
    string question1 = "����� ��������������� ��������� ����� ����� ������ ��� �����, ����� ������������ � �����������?";
    string question2 = "������ ��, ��� ���� ��������� ���������� � ���������� ���������?";
    try {
        db << "CREATE TABLE IF NOT EXISTS users ("
            "id INTEGER PRIMARY KEY,"
            "question1 TEXT,"
            "question2 TEXT,"
            "question3 TEXT,"
            "question4 TEXT,"
            "question5 TEXT,"
            "question1answer TEXT,"
            "question2answer TEXT,"
            "question3answer TEXT,"
            "question4answer TEXT,"
            "question5answer TEXT"
            ");";
        /*, question3, question4, question5, question1answer, question2answer, question3answer, question4answer, question5answer*/
        db << "INSERT INTO users( question1, question2) VALUES(? , ? )" /* , ? , ? , ? , ? , ? , ? , ? , ? */ << "����� ��������������� ��������� ����� ����� ������ ��� �����, ����� ������������ � �����������?" << "������ ��, ��� ���� ��������� ���������� � ���������� ���������?";  /*<< "������ ��������� ��������� � ���� ��������� ���������� ? " << "���������� �� � ���������� ������� ����������� ? " << "hi ? " << "Aliens" << "Yes" << "Because" << "No, it's bread" << "Hello, world";
    */}
    catch (sqlite_exception& e) { cout << e.what(); }
}

database Database::get_db() { return db; }
#include "users.h"

QString Usernames[100] = {"admin", "User1","User2","User3"};
QString Passwords[100] = {"admin", "1234", "1101", "1102"};
int Age[100] = {20,21,18,19};
int usersCount = 4;
void signUp(QString un, QString pw, int age){
Usernames [ usersCount ] = un;
Passwords[usersCount ] = pw;
Age[usersCount] = age;
usersCount++;
}



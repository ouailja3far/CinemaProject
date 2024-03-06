#ifndef USERS_H
#define USERS_H
#include <QString>

extern QString Usernames[100];
extern QString Passwords[100];
extern int Age[100];
extern int usersCount;
extern void singUp(QString un, QString pw, int age);

#endif // USERS_H

#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "welcomewindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->labelError->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButtonLogin_clicked()
{
    QString edName = ui->lineEditUsername->text();
    QString edPass = ui->lineEditPassword->text();
    for(int i=0; i<usersCount; i++){
    if((edName == Usernames[i]) && (edPass == Passwords[i]))
    {
        hide();
        WelcomeWindow *welcomeWindow = new WelcomeWindow(this, Usernames[i], Age[i]);
        welcomeWindow->show();
    }
    else
    {
        ui->labelError->setVisible(true);
    }
    }
}


void LoginWindow::on_pushButtonRegister_clicked()
{
    hide();
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

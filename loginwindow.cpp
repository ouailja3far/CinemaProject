#include "loginwindow.h"
#include "ui_loginwindow.h"

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
    QString usern = "jojo";
    QString userp = "roro";
    int age = 9;
    QString edName = ui->lineEditUsername->text();
    QString edPass = ui->lineEditPassword->text();

    if((edName == usern) && (edPass == userp))
    {
        hide();
        WelcomeWindow *welcomeWindow = new WelcomeWindow(this, usern, age);
        welcomeWindow->show();
    }
    else
    {
        ui->labelError->setVisible(true);
    }
}


void LoginWindow::on_pushButtonRegister_clicked()
{
    // show register window
}

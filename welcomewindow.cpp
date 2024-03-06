#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, QString wUsername, int wAge)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString strAge = QString :: number ( wAge );
    ui->labelHello->setText("Hello " + wUsername + " " + strAge);
    QPixmap pix("C:\\Users\\ouail estoyloco\\Documents\\CinemaProject\\elmo.gif");
    int w = ui->labelWelcomePic->width();
    int h = ui->labelWelcomePic->height();
    ui->labelWelcomePic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButtonLogout_clicked()
{
    hide();
    LoginWindow *loginWindow = new LoginWindow(this);
    loginWindow->show();
}

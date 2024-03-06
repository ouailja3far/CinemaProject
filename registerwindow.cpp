#include "registerwindow.h"
#include "loginwindow.h"
#include "ui_registerwindow.h"
#include "users.h"
RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    //hiding error messages
    ui->ageError->setVisible(false);
    ui->passwordError->setVisible(false);
    ui->scndPasswordError->setVisible(false);
    ui->usernameError->setVisible(false);
    ui->radioButtonError->setVisible(false);
    ui->checkboxError->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{

    delete ui;
}

void RegisterWindow::on_pushButtonRegister_clicked()
{
    QString tempUsername = "", stringYear, stringDay, tempPassword= "", tempGender = "", tempaccountType = "", tempFavouriteGenres[6], tempScndPassword= "";
    int tempAge,favNbr=0;
    //getting the data
    tempScndPassword = ui->lineEditscndPassword->text();
    tempUsername = ui->lineEditUsername->text();
    tempPassword = ui->lineEditPassword->text();
    stringYear = ui->lineEditYear->text();
    stringDay = ui->lineEditDay->text();
    if(stringYear.toInt()){
    tempAge = 2024 - stringYear.toInt();
    ui->ageError->setVisible(false);
    }else{
        ui->ageError->setVisible(true);
    }
    //gender
    if(ui->radioButtonFemale->isChecked()){
        tempGender = "Female";
        ui->radioButtonError->setVisible(false);
    }else if(ui->radioButtonMale){
        tempGender = "Male";
        ui->radioButtonError->setVisible(false);

    }else{
        ui->radioButtonError->setVisible(true);
    }
    //account type
    if(ui->radioButtonAdmin->isChecked()){
        tempaccountType = "admin";
        ui->radioButtonError->setVisible(false);
    }else if (ui->radioButtonUser->isChecked()){
        tempaccountType = "user";
        ui->radioButtonError->setVisible(false);
    }else{
        ui->radioButtonError->setVisible(true);
    }
    //favorite genre
    if(ui->checkBoxRom->isChecked()){
        tempFavouriteGenres[favNbr++] = "Romance";
        ui->checkboxError->setVisible(false);
    }else if (ui->checkBoxAction->isChecked()){
        tempFavouriteGenres[favNbr++] = "Action";
        ui->checkboxError->setVisible(false);
    }else if (ui->checkBoxCom->isChecked()){
        tempFavouriteGenres[favNbr++] = "Comedy";
        ui->checkboxError->setVisible(false);
    }else if (ui->checkBoxHorror->isChecked()){
        tempFavouriteGenres[favNbr++] = "Horror";
        ui->checkboxError->setVisible(false);
    }else if (ui->checkBoxDrama->isChecked()){
        tempFavouriteGenres[favNbr++] = "Drama";
        ui->checkboxError->setVisible(false);
    }else if (ui->checkBoxOther->isChecked()){
        tempFavouriteGenres[favNbr++] = "Other";
        ui->checkboxError->setVisible(false);
    }else{
        ui->checkboxError->setVisible(true);
    }
    //matching passwords
    if(tempPassword != tempScndPassword || tempScndPassword.isEmpty()){
        ui->scndPasswordError->setVisible(true);
    }
    else{
        ui->scndPasswordError->setVisible(false);
    }
    //matching usernames
    for(int i =0 ; i<usersCount; i++){
        if(Usernames[i] == tempUsername ){
            ui->usernameError->setVisible(true);
        }
    }
    //registration
    if(!(ui->usernameError->isVisible() || ui->passwordError->isVisible() || ui->scndPasswordError->isVisible() || ui->radioButtonError->isVisible() || ui->checkboxError->isVisible() || ui->ageError->isVisible())){
        Usernames [ usersCount] = tempUsername;
        Passwords[usersCount ] = tempPassword;
        Age[usersCount] = tempAge;
        usersCount++;
        this->close();
    }



}


#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setStyleSheet("background-color: darkCyan");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("background-color: rgb(0,114,114)");
}
void MainWindow::on_pushButton_released()
{
    ui->pushButton->setStyleSheet("background-color: darkCyan");
}

void MainWindow::on_pushButton_clicked()
{
    std::string charSet(""),
                password("");

    if (ui->checkBox_5->isChecked())
    {
        charSet = ui->lineEdit->text().toStdString();
    }
    else
    {
        if (ui->checkBox_1->isChecked())
        {
            charSet+="abcdefghijklmnopqrstuvwxyz";
        }
        if (ui->checkBox_2->isChecked())
        {
            charSet+="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }
        if (ui->checkBox_3->isChecked())
        {
            charSet+="1234567890";
        }
        if (ui->checkBox_4->isChecked())
        {
            charSet+="!@#$%^&*()";
        }
    }

    if (charSet!="")
    {
        for (int i=0; i<ui->spinBox->value(); ++i)
        {
            password+=charSet.at(rand()%(int)charSet.length());
        }
        ui->plainTextEdit->appendPlainText(output.c_str());
    }
}





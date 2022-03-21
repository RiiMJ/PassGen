#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include <QApplication>

//initialise variables
std:: string password("");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set color of push buttons
    ui->pushButton->setStyleSheet("background-color: darkCyan");
    ui->pushButton_2->setStyleSheet("background-color: darkCyan");
    ui->pushButton_3->setStyleSheet("background-color: darkCyan");

}

MainWindow::~MainWindow()
{
    delete ui;
}

//change color when button pressed
void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("background-color: rgb(0,114,114)");
}
void MainWindow::on_pushButton_released()
{
    ui->pushButton->setStyleSheet("background-color: darkCyan");
}

//generate password when button clicked
void MainWindow::on_pushButton_clicked()
{
    std:: string charSet("");
    password = "";

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
    }
    ui->plainTextEdit->appendPlainText(password.c_str());

}

// write files
void writeFile()
{
    QFile file("record.txt");
    if (file.open(QIODevice::Append))
    {
        //qInfo("opened");
        QTextStream stream (&file);
        stream<<password.c_str();
        file.flush();
    }
    else
    {
        qInfo("Not opened");
    }
    file.close();
}


// read files
void readFile()
{
    QFile file("record.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream (&file);
        while(!stream.atEnd()){
            QString line = stream.readLine();
            qInfo()<<line;
        }
    }
    else
    {
        qInfo("Not opened");
    }
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    qInfo()<<password.c_str();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit->clear();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    writeFile();
    readFile();
    return a.exec();
}


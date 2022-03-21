#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include <QApplication>

std::string charSet(""),
            output("");
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

void MainWindow::on_pushButton_clicked()
{


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
            output+=charSet.at(rand()%(int)charSet.length());
        }


        ui->plainTextEdit->appendPlainText(output.c_str());
        qInfo()<<output.c_str();
    }
}

void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("background-color: rgb(0,114,114)");
}
void MainWindow::on_pushButton_released()
{
    ui->pushButton->setStyleSheet("background-color: darkCyan");
}


// write files
void writeFile()
{
    QFile file("record.txt");
    if (file.open(QIODevice::Append))
    {
        qInfo("opened");
        QTextStream stream (&file);
        stream<<output.c_str();
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
        qInfo("opened");
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    writeFile();
    readFile();
    return a.exec();
}


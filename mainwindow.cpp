#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include "fraction.h"
#include "func.h"
#include <iostream>
#include <sstream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::vector<fraction> f_vector;
    std::vector<std::string> s_vector(9);
    s_vector[0] = ui->inputBox1->displayText().toStdString();
    s_vector[1] = ui->inputBox2->displayText().toStdString();
    s_vector[2] = ui->inputBox3->displayText().toStdString();
    s_vector[3] = ui->inputBox4->displayText().toStdString();
    s_vector[4] = ui->inputBox5->displayText().toStdString();
    s_vector[5] = ui->inputBox6->displayText().toStdString();
    s_vector[6] = ui->inputBox7->displayText().toStdString();
    s_vector[7] = ui->inputBox8->displayText().toStdString();
    s_vector[8] = ui->inputBox9->displayText().toStdString();

    f_vector = string_to_fraction(s_vector);

    matrix a(f_vector, 3, 3);
    a = a.inverse();

   ui->resultBox1->addAction("qwer");

}

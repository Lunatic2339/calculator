#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include "fraction.h"

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

void MainWindow::on_pushButton_clicked(){
    fraction b[3*3];
    matrix a(3, 3, b);
    int a1 = ui->lineEdit->displayText().toInt();

    std::cout << a.power(a1);
}

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
    std::vector<fraction> b[9];
    matrix a = (b, 3, 3);
    int b[0] = ui->lineEdit->displayText().toInt();

    std::cout << a.power(b[0]);
}

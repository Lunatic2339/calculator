#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>

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
    std::vector<fraction> b(9, 0);
    matrix a(b, 3, 3);
    std::string b[0] = ui->lineEdit->displayText();

    ui->lineEdit_2->setText(b[0]);
}

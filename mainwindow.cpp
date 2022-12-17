#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include "fraction.h"

#include <iostream>
#include <sstream>
#include <string>

std::vector<fraction> string_to_fraction(std::vector<std::string> s_v)
{
    std::vector<fraction> result;
    fraction f_temp(0,1);
    std::stringstream ss;
    std::stringstream ssInt;
    std::stringstream ssInt2;
    std::string temp;
    int n_temp;
    int d_temp;
    std::vector<std::string> v_temp;
    for (int i = 0; i < s_v.size(); ++i)
    {
       ss.str(s_v[i]);
       while (std::getline(ss, temp, '/'))
       {
            std::cout << temp;
            v_temp.push_back(temp);
       }
       ssInt.str(v_temp[0]);
       ssInt >> n_temp;
       f_temp.set(n_temp, 1);
       if(v_temp.size() == 2)
       {
            ssInt2.str(v_temp[1]);
            ssInt2 >> d_temp;
            f_temp.set(n_temp, d_temp);
       }
       result.push_back(f_temp);
       v_temp.clear();
       f_temp.set(0, 1);
    }
    return result;
}

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
    std::vector<fraction> f_vector2;

    std::vector<std::string> s_vector(9, "0");
    std::vector<std::string> s_vector2;

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

    f_vector2 = a.matrix_to_vector();
    s_vector2 = fraction_to_string(f_vector2);

    ui->resultBox1->setText(QString::fromStdString(s_vector2[0]));
    ui->resultBox2->setText(QString::fromStdString(s_vector2[1]));
    ui->resultBox3->setText(QString::fromStdString(s_vector2[2]));
    ui->resultBox4->setText(QString::fromStdString(s_vector2[3]));
    ui->resultBox5->setText(QString::fromStdString(s_vector2[4]));
    ui->resultBox6->setText(QString::fromStdString(s_vector2[5]));
    ui->resultBox7->setText(QString::fromStdString(s_vector2[6]));
    ui->resultBox8->setText(QString::fromStdString(s_vector2[7]));
    ui->resultBox9->setText(QString::fromStdString(s_vector2[8]));


}

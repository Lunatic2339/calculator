#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>

#include <iostream>
#include <sstream>
#include <string>

std::vector<fraction> string_to_fraction(std::vector<std::string> s_v)
{
    std::stringstream ss;
    std::string s_temp;
    std::vector<std::string> s_temp_v;
    fraction f_temp;
    std::vector<fraction> result;
    for (int i = 0; i < s_v.size(); ++i)
    {
        f_temp.setNum(std::stoi(s_v[i]));
        while (std::getline(ss, s_temp, '/'))
        {
            s_temp_v.push_back(s_temp);
        }
        if (s_temp_v.size() == 2) f_temp.setDenom(std::stoi(s_temp_v[1]));
        result.push_back(f_temp);
        f_temp.set(0, 1);
    }
    return result;
}
std::vector<std::string> fraction_to_string(std::vector<fraction> f_v)
{
    std::vector<std::string> s_v(f_v.size());
    for(int i = 0; i < f_v.size(); ++i)
    {
        if(f_v[i].denom() * f_v[i].num() < 0) s_v[i].push_back('-');
        s_v[i] = s_v[i] + std::to_string(std::abs(f_v[i].num()));
        if(f_v[i].denom() != 1)
        {
            s_v[i].push_back('/');
            s_v[i] = s_v[i] + std::to_string(std::abs(f_v[i].denom()));
        }
    }
    return s_v;
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

    std::vector<std::string> s_vector(9);
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
    std::cout << a.det();
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

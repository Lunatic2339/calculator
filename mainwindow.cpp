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
    for (int i = 0; i < (int)s_v.size(); ++i)
    {
        f_temp.setNum(std::stoi(s_v[i]));
        size_t mid = s_v[i].find('/');
        if(mid != std::string::npos)
        {
            std::string next = s_v[i].substr(mid+1, s_v[i].size()-1);
            f_temp.setDenom(std::stoi(next));
        }
        result.push_back(f_temp);
        f_temp.set(0, 1);
    }
    return result;
}
std::vector<std::string> fraction_to_string(std::vector<fraction> f_v)
{
    std::vector<std::string> s_v(f_v.size());
    for(int i = 0; i < (int)f_v.size(); ++i)
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
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inverseButton1_clicked()
{
    std::vector<fraction> f_vectorA;
    std::vector<fraction> f_vectorA2;

    std::vector<std::string> s_vectorA(9, "");
    std::vector<std::string> s_vectorA2;

    s_vectorA[0] = ui->inputBox1->displayText().toStdString();
    s_vectorA[1] = ui->inputBox2->displayText().toStdString();
    s_vectorA[2] = ui->inputBox3->displayText().toStdString();
    s_vectorA[3] = ui->inputBox4->displayText().toStdString();
    s_vectorA[4] = ui->inputBox5->displayText().toStdString();
    s_vectorA[5] = ui->inputBox6->displayText().toStdString();
    s_vectorA[6] = ui->inputBox7->displayText().toStdString();
    s_vectorA[7] = ui->inputBox8->displayText().toStdString();
    s_vectorA[8] = ui->inputBox9->displayText().toStdString();

    f_vectorA = string_to_fraction(s_vectorA);

    matrix a(f_vectorA, 3, 3);
    a = a.inverse();

    f_vectorA2 = a.matrix_to_vector();
    s_vectorA2 = fraction_to_string(f_vectorA2);

    ui->resultBox1->setText(QString::fromStdString(s_vectorA2[0]));
    ui->resultBox2->setText(QString::fromStdString(s_vectorA2[1]));
    ui->resultBox3->setText(QString::fromStdString(s_vectorA2[2]));
    ui->resultBox4->setText(QString::fromStdString(s_vectorA2[3]));
    ui->resultBox5->setText(QString::fromStdString(s_vectorA2[4]));
    ui->resultBox6->setText(QString::fromStdString(s_vectorA2[5]));
    ui->resultBox7->setText(QString::fromStdString(s_vectorA2[6]));
    ui->resultBox8->setText(QString::fromStdString(s_vectorA2[7]));
    ui->resultBox9->setText(QString::fromStdString(s_vectorA2[8]));
}

void MainWindow::on_inverseButton2_clicked()
{
    std::vector<fraction> f_vectorB;
    std::vector<fraction> f_vectorB2;

    std::vector<std::string> s_vectorB(9, "");
    std::vector<std::string> s_vectorB2;

    s_vectorB[0] = ui->inputBox1_2->displayText().toStdString();
    s_vectorB[1] = ui->inputBox2_2->displayText().toStdString();
    s_vectorB[2] = ui->inputBox3_2->displayText().toStdString();
    s_vectorB[3] = ui->inputBox4_2->displayText().toStdString();
    s_vectorB[4] = ui->inputBox5_2->displayText().toStdString();
    s_vectorB[5] = ui->inputBox6_2->displayText().toStdString();
    s_vectorB[6] = ui->inputBox7_2->displayText().toStdString();
    s_vectorB[7] = ui->inputBox8_2->displayText().toStdString();
    s_vectorB[8] = ui->inputBox9_2->displayText().toStdString();


    f_vectorB = string_to_fraction(s_vectorB);

    matrix b(f_vectorB, 3, 3);
    b = b.inverse();

    f_vectorB2 = b.matrix_to_vector();
    s_vectorB2 = fraction_to_string(f_vectorB2);

    ui->resultBox1->setText(QString::fromStdString(s_vectorB2[0]));
    ui->resultBox2->setText(QString::fromStdString(s_vectorB2[1]));
    ui->resultBox3->setText(QString::fromStdString(s_vectorB2[2]));
    ui->resultBox4->setText(QString::fromStdString(s_vectorB2[3]));
    ui->resultBox5->setText(QString::fromStdString(s_vectorB2[4]));
    ui->resultBox6->setText(QString::fromStdString(s_vectorB2[5]));
    ui->resultBox7->setText(QString::fromStdString(s_vectorB2[6]));
    ui->resultBox8->setText(QString::fromStdString(s_vectorB2[7]));
    ui->resultBox9->setText(QString::fromStdString(s_vectorB2[8]));

}


void MainWindow::on_plusButton_clicked()
{
    std::vector<fraction> f_vectorC;
    std::vector<std::string> s_vectorC;

    std::vector<fraction> f_vectorA;
    std::vector<std::string> s_vectorA(9, "");

    s_vectorA[0] = ui->inputBox1->displayText().toStdString();
    s_vectorA[1] = ui->inputBox2->displayText().toStdString();
    s_vectorA[2] = ui->inputBox3->displayText().toStdString();
    s_vectorA[3] = ui->inputBox4->displayText().toStdString();
    s_vectorA[4] = ui->inputBox5->displayText().toStdString();
    s_vectorA[5] = ui->inputBox6->displayText().toStdString();
    s_vectorA[6] = ui->inputBox7->displayText().toStdString();
    s_vectorA[7] = ui->inputBox8->displayText().toStdString();
    s_vectorA[8] = ui->inputBox9->displayText().toStdString();

    std::vector<fraction> f_vectorB;
    std::vector<std::string> s_vectorB(9, "");

    s_vectorB[0] = ui->inputBox1_2->displayText().toStdString();
    s_vectorB[1] = ui->inputBox2_2->displayText().toStdString();
    s_vectorB[2] = ui->inputBox3_2->displayText().toStdString();
    s_vectorB[3] = ui->inputBox4_2->displayText().toStdString();
    s_vectorB[4] = ui->inputBox5_2->displayText().toStdString();
    s_vectorB[5] = ui->inputBox6_2->displayText().toStdString();
    s_vectorB[6] = ui->inputBox7_2->displayText().toStdString();
    s_vectorB[7] = ui->inputBox8_2->displayText().toStdString();
    s_vectorB[8] = ui->inputBox9_2->displayText().toStdString();

    f_vectorA = string_to_fraction(s_vectorA);
    matrix a(f_vectorA, 3, 3);

    f_vectorB = string_to_fraction(s_vectorB);
    matrix b(f_vectorB, 3, 3);

    matrix c = a + b;
    f_vectorC = c.matrix_to_vector();
    s_vectorC = fraction_to_string(f_vectorC);

    ui->resultBox1->setText(QString::fromStdString(s_vectorC[0]));
    ui->resultBox2->setText(QString::fromStdString(s_vectorC[1]));
    ui->resultBox3->setText(QString::fromStdString(s_vectorC[2]));
    ui->resultBox4->setText(QString::fromStdString(s_vectorC[3]));
    ui->resultBox5->setText(QString::fromStdString(s_vectorC[4]));
    ui->resultBox6->setText(QString::fromStdString(s_vectorC[5]));
    ui->resultBox7->setText(QString::fromStdString(s_vectorC[6]));
    ui->resultBox8->setText(QString::fromStdString(s_vectorC[7]));
    ui->resultBox9->setText(QString::fromStdString(s_vectorC[8]));
}

void MainWindow::on_minusButton_clicked()
{
    std::vector<fraction> f_vectorC;
    std::vector<std::string> s_vectorC;

    std::vector<fraction> f_vectorA;
    std::vector<std::string> s_vectorA(9, "");

    s_vectorA[0] = ui->inputBox1->displayText().toStdString();
    s_vectorA[1] = ui->inputBox2->displayText().toStdString();
    s_vectorA[2] = ui->inputBox3->displayText().toStdString();
    s_vectorA[3] = ui->inputBox4->displayText().toStdString();
    s_vectorA[4] = ui->inputBox5->displayText().toStdString();
    s_vectorA[5] = ui->inputBox6->displayText().toStdString();
    s_vectorA[6] = ui->inputBox7->displayText().toStdString();
    s_vectorA[7] = ui->inputBox8->displayText().toStdString();
    s_vectorA[8] = ui->inputBox9->displayText().toStdString();

    std::vector<fraction> f_vectorB;
    std::vector<std::string> s_vectorB(9, "");

    s_vectorB[0] = ui->inputBox1_2->displayText().toStdString();
    s_vectorB[1] = ui->inputBox2_2->displayText().toStdString();
    s_vectorB[2] = ui->inputBox3_2->displayText().toStdString();
    s_vectorB[3] = ui->inputBox4_2->displayText().toStdString();
    s_vectorB[4] = ui->inputBox5_2->displayText().toStdString();
    s_vectorB[5] = ui->inputBox6_2->displayText().toStdString();
    s_vectorB[6] = ui->inputBox7_2->displayText().toStdString();
    s_vectorB[7] = ui->inputBox8_2->displayText().toStdString();
    s_vectorB[8] = ui->inputBox9_2->displayText().toStdString();

    matrix a(f_vector, 3, 3);
    if(a.det() == 0){
        ui->textEdit->setPlainText("Error");
        ui->resultBox1->setText(QString::fromStdString("0"));
        ui->resultBox2->setText(QString::fromStdString("0"));
        ui->resultBox3->setText(QString::fromStdString("0"));
        ui->resultBox4->setText(QString::fromStdString("0"));
        ui->resultBox5->setText(QString::fromStdString("0"));
        ui->resultBox6->setText(QString::fromStdString("0"));
        ui->resultBox7->setText(QString::fromStdString("0"));
        ui->resultBox8->setText(QString::fromStdString("0"));
        ui->resultBox9->setText(QString::fromStdString("0"));
    }
    else{
        ui->textEdit->setPlainText("");
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
}

void MainWindow::on_mulButton_clicked()
{
    std::vector<fraction> f_vectorC;
    std::vector<std::string> s_vectorC;

    std::vector<fraction> f_vectorA;
    std::vector<std::string> s_vectorA(9, "");

    s_vectorA[0] = ui->inputBox1->displayText().toStdString();
    s_vectorA[1] = ui->inputBox2->displayText().toStdString();
    s_vectorA[2] = ui->inputBox3->displayText().toStdString();
    s_vectorA[3] = ui->inputBox4->displayText().toStdString();
    s_vectorA[4] = ui->inputBox5->displayText().toStdString();
    s_vectorA[5] = ui->inputBox6->displayText().toStdString();
    s_vectorA[6] = ui->inputBox7->displayText().toStdString();
    s_vectorA[7] = ui->inputBox8->displayText().toStdString();
    s_vectorA[8] = ui->inputBox9->displayText().toStdString();

    std::vector<fraction> f_vectorB;
    std::vector<std::string> s_vectorB(9, "");

    s_vectorB[0] = ui->inputBox1_2->displayText().toStdString();
    s_vectorB[1] = ui->inputBox2_2->displayText().toStdString();
    s_vectorB[2] = ui->inputBox3_2->displayText().toStdString();
    s_vectorB[3] = ui->inputBox4_2->displayText().toStdString();
    s_vectorB[4] = ui->inputBox5_2->displayText().toStdString();
    s_vectorB[5] = ui->inputBox6_2->displayText().toStdString();
    s_vectorB[6] = ui->inputBox7_2->displayText().toStdString();
    s_vectorB[7] = ui->inputBox8_2->displayText().toStdString();
    s_vectorB[8] = ui->inputBox9_2->displayText().toStdString();

    matrix a(f_vector, 3, 3);
    if(a.det() == 0){
        ui->textEdit->setPlainText("Error");
        ui->resultBox1->setText(QString::fromStdString("0"));
        ui->resultBox2->setText(QString::fromStdString("0"));
        ui->resultBox3->setText(QString::fromStdString("0"));
        ui->resultBox4->setText(QString::fromStdString("0"));
        ui->resultBox5->setText(QString::fromStdString("0"));
        ui->resultBox6->setText(QString::fromStdString("0"));
        ui->resultBox7->setText(QString::fromStdString("0"));
        ui->resultBox8->setText(QString::fromStdString("0"));
        ui->resultBox9->setText(QString::fromStdString("0"));
    }
    else{
        ui->textEdit->setPlainText("");
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
}

void MainWindow::on_plusButton_clicked(){
    std::vector<fraction> f_vector;
    std::vector<fraction> f_vector2;
    std::vector<fraction> f_vector3;

    std::vector<std::string> s_vector(9);
    std::vector<std::string> s_vector2(9);
    std::vector<std::string> s_vector3;

    s_vector[0] = ui->inputBox1->displayText().toStdString();
    s_vector[1] = ui->inputBox2->displayText().toStdString();
    s_vector[2] = ui->inputBox3->displayText().toStdString();
    s_vector[3] = ui->inputBox4->displayText().toStdString();
    s_vector[4] = ui->inputBox5->displayText().toStdString();
    s_vector[5] = ui->inputBox6->displayText().toStdString();
    s_vector[6] = ui->inputBox7->displayText().toStdString();
    s_vector[7] = ui->inputBox8->displayText().toStdString();
    s_vector[8] = ui->inputBox9->displayText().toStdString();
    s_vector2[0] = ui->inputBox1_2->displayText().toStdString();
    s_vector2[1] = ui->inputBox2_2->displayText().toStdString();
    s_vector2[2] = ui->inputBox3_2->displayText().toStdString();
    s_vector2[3] = ui->inputBox4_2->displayText().toStdString();
    s_vector2[4] = ui->inputBox5_2->displayText().toStdString();
    s_vector2[5] = ui->inputBox6_2->displayText().toStdString();
    s_vector2[6] = ui->inputBox7_2->displayText().toStdString();
    s_vector2[7] = ui->inputBox8_2->displayText().toStdString();
    s_vector2[8] = ui->inputBox9_2->displayText().toStdString();


    f_vector = string_to_fraction(s_vector);
    f_vector2 = string_to_fraction(s_vector2);

    matrix a(f_vector, 3, 3);
    matrix b(f_vector2, 3, 3);
    matrix c = a+b;

    f_vector3 = c.matrix_to_vector();
    s_vector3 = fraction_to_string(f_vector3);

    ui->resultBox1->setText(QString::fromStdString(s_vector3[0]));
    ui->resultBox2->setText(QString::fromStdString(s_vector3[1]));
    ui->resultBox3->setText(QString::fromStdString(s_vector3[2]));
    ui->resultBox4->setText(QString::fromStdString(s_vector3[3]));
    ui->resultBox5->setText(QString::fromStdString(s_vector3[4]));
    ui->resultBox6->setText(QString::fromStdString(s_vector3[5]));
    ui->resultBox7->setText(QString::fromStdString(s_vector3[6]));
    ui->resultBox8->setText(QString::fromStdString(s_vector3[7]));
    ui->resultBox9->setText(QString::fromStdString(s_vector3[8]));
}
void MainWindow::on_minusButton_clicked(){
    std::vector<fraction> f_vector;
    std::vector<fraction> f_vector2;
    std::vector<fraction> f_vector3;

    std::vector<std::string> s_vector(9);
    std::vector<std::string> s_vector2(9);
    std::vector<std::string> s_vector3;

    s_vector[0] = ui->inputBox1->displayText().toStdString();
    s_vector[1] = ui->inputBox2->displayText().toStdString();
    s_vector[2] = ui->inputBox3->displayText().toStdString();
    s_vector[3] = ui->inputBox4->displayText().toStdString();
    s_vector[4] = ui->inputBox5->displayText().toStdString();
    s_vector[5] = ui->inputBox6->displayText().toStdString();
    s_vector[6] = ui->inputBox7->displayText().toStdString();
    s_vector[7] = ui->inputBox8->displayText().toStdString();
    s_vector[8] = ui->inputBox9->displayText().toStdString();
    s_vector2[0] = ui->inputBox1_2->displayText().toStdString();
    s_vector2[1] = ui->inputBox2_2->displayText().toStdString();
    s_vector2[2] = ui->inputBox3_2->displayText().toStdString();
    s_vector2[3] = ui->inputBox4_2->displayText().toStdString();
    s_vector2[4] = ui->inputBox5_2->displayText().toStdString();
    s_vector2[5] = ui->inputBox6_2->displayText().toStdString();
    s_vector2[6] = ui->inputBox7_2->displayText().toStdString();
    s_vector2[7] = ui->inputBox8_2->displayText().toStdString();
    s_vector2[8] = ui->inputBox9_2->displayText().toStdString();


    f_vector = string_to_fraction(s_vector);
    f_vector2 = string_to_fraction(s_vector2);

    matrix a(f_vector, 3, 3);
    matrix b(f_vector2, 3, 3);
    matrix c = a-b;

    f_vector3 = c.matrix_to_vector();
    s_vector3 = fraction_to_string(f_vector3);

    ui->resultBox1->setText(QString::fromStdString(s_vector3[0]));
    ui->resultBox2->setText(QString::fromStdString(s_vector3[1]));
    ui->resultBox3->setText(QString::fromStdString(s_vector3[2]));
    ui->resultBox4->setText(QString::fromStdString(s_vector3[3]));
    ui->resultBox5->setText(QString::fromStdString(s_vector3[4]));
    ui->resultBox6->setText(QString::fromStdString(s_vector3[5]));
    ui->resultBox7->setText(QString::fromStdString(s_vector3[6]));
    ui->resultBox8->setText(QString::fromStdString(s_vector3[7]));
    ui->resultBox9->setText(QString::fromStdString(s_vector3[8]));
}
void MainWindow::on_mulButton_clicked(){
    std::vector<fraction> f_vector;
    std::vector<fraction> f_vector2;
    std::vector<fraction> f_vector3;

    std::vector<std::string> s_vector(9);
    std::vector<std::string> s_vector2(9);
    std::vector<std::string> s_vector3;

    s_vector[0] = ui->inputBox1->displayText().toStdString();
    s_vector[1] = ui->inputBox2->displayText().toStdString();
    s_vector[2] = ui->inputBox3->displayText().toStdString();
    s_vector[3] = ui->inputBox4->displayText().toStdString();
    s_vector[4] = ui->inputBox5->displayText().toStdString();
    s_vector[5] = ui->inputBox6->displayText().toStdString();
    s_vector[6] = ui->inputBox7->displayText().toStdString();
    s_vector[7] = ui->inputBox8->displayText().toStdString();
    s_vector[8] = ui->inputBox9->displayText().toStdString();
    s_vector2[0] = ui->inputBox1_2->displayText().toStdString();
    s_vector2[1] = ui->inputBox2_2->displayText().toStdString();
    s_vector2[2] = ui->inputBox3_2->displayText().toStdString();
    s_vector2[3] = ui->inputBox4_2->displayText().toStdString();
    s_vector2[4] = ui->inputBox5_2->displayText().toStdString();
    s_vector2[5] = ui->inputBox6_2->displayText().toStdString();
    s_vector2[6] = ui->inputBox7_2->displayText().toStdString();
    s_vector2[7] = ui->inputBox8_2->displayText().toStdString();
    s_vector2[8] = ui->inputBox9_2->displayText().toStdString();


    f_vector = string_to_fraction(s_vector);
    f_vector2 = string_to_fraction(s_vector2);

    matrix a(f_vector, 3, 3);
    matrix b(f_vector2, 3, 3);
    matrix c = a*b;

    f_vector3 = c.matrix_to_vector();
    s_vector3 = fraction_to_string(f_vector3);

    ui->resultBox1->setText(QString::fromStdString(s_vector3[0]));
    ui->resultBox2->setText(QString::fromStdString(s_vector3[1]));
    ui->resultBox3->setText(QString::fromStdString(s_vector3[2]));
    ui->resultBox4->setText(QString::fromStdString(s_vector3[3]));
    ui->resultBox5->setText(QString::fromStdString(s_vector3[4]));
    ui->resultBox6->setText(QString::fromStdString(s_vector3[5]));
    ui->resultBox7->setText(QString::fromStdString(s_vector3[6]));
    ui->resultBox8->setText(QString::fromStdString(s_vector3[7]));
    ui->resultBox9->setText(QString::fromStdString(s_vector3[8]));
}

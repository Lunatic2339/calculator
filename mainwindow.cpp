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

std::vector<std::vector<int>> string_to_func(std::string input)
{
    std::vector<std::vector<int>> a(6, std::vector<int>(6, 0));
    std::vector<std::string> split_vector;
    std::string temp;
    int idx = 0;
    for (int i = 1; i < input.size(); ++i)
    {
        if (input[i] == '+' || input[i] == '-')
        {
            split_vector.push_back(input.substr(idx, i-idx));
            idx = i;
        }
    }
    if (split_vector.size() != 0) split_vector.push_back(input.substr(idx, split_vector.size()-idx));
    if (split_vector.size() == 0) split_vector.push_back(input);
    for (std::string s : split_vector)
    {
        int c;
        try {
            c = std::stoi(s);
        }
        catch(const std::exception& e)
        {
            c = 1;
        }
        int x = 0;
        int y = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (s[i] == 'x')
            {
                if (i == (int)s.size() - 1)
                {
                    x = 1;
                }
                else
                {
                    if (s[i + 1] == '^')
                    {
                        x = std::stoi(s.substr(i + 2, s.size() - 1));
                    }
                    else if (s[i + 1] == 'y') x = 1;
                }
            }
            if (s[i] == 'y')
            {
                if (i == (int)s.size() - 1)
                {
                    y = 1;
                }
                else
                {
                    if (s[i + 1] == '^')
                    {
                        y = std::stoi(s.substr(i + 2, s.size() - 1));
                    }
                    else if (s[i + 1] == 'x') y = 1;
                }
            }
        }
        a[x][y] = c;
    }
    return a;
}
std::string func_to_string(std::vector<std::vector<int>> func)
{
    std::string result;
    int dummy = 0;
    for (int i = func.size() - 1; i >= 0; --i)
    {
        for (int j = func[i].size()-1; j >= 0; --j)
        {
            if (func[i][j] != 0)
            {
                if (dummy != 0)
                {
                    if (func[i][j] > 0) result.push_back('+');
                }
                result = result + std::to_string(func[i][j]);
                if (i != 0)
                {
                    result.push_back('x');
                    if (i != 1)
                    {
                        result.push_back('^');
                        result = result + std::to_string(i);
                    }
                    dummy++;

                }
                if (j != 0)
                {
                    result.push_back('y');
                    if (j != 1)
                    {
                        result.push_back('^');
                        result = result + std::to_string(j);
                    }
                    dummy++;
                }
            }
        }
    }
    return result;
}
std::vector<std::vector<int>> dif(std::vector<std::vector<int>> vv, char c)
{
    if (c == 'x')
    {
        for (int i = 1; i < vv.size(); ++i)
        {
            for (int& j : vv[i])
            {
                j = j * i;
            }
            vv[i - 1] = vv[i];
        }
        vv[5] = std::vector<int>(6, 0);
    }
    if (c == 'y')
    {
        for (int i = 1; i < vv.size(); ++i)
        {
            for (int j = 0; j < vv[i].size(); ++j)
            {
                vv[j][i] = vv[j][i] * i;
                vv[j][i - 1] = vv[j][i];
            }

        }
        for (int i = 0; i < vv.size(); ++i)
        {
            vv[i][5] = 0;
        }
    }
    return vv;
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
    if(!ui->checkBox->isChecked())
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
    }
}

void MainWindow::on_inverseButton2_clicked()
{
    if(!ui->checkBox->isChecked())
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
        if(b.det() == 0){
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
    }
}

void MainWindow::on_plusButton_clicked()
{
    if(!ui->checkBox->isChecked())
    {
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
}

void MainWindow::on_minusButton_clicked()
{
    if(!ui->checkBox->isChecked())
    {
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
}
void MainWindow::on_mulButton_clicked()
{
    if(!ui->checkBox->isChecked())
    {
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
}
void MainWindow::on_powerButton1_clicked()
{
    if(!ui->checkBox->isChecked())
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
        a = a.power(ui->powerInput1->displayText().toInt());

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
}
void MainWindow::on_powerButton2_clicked()
{
    if(!ui->checkBox->isChecked())
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
        b = b.power(ui->powerInput2->displayText().toInt());

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
}

void MainWindow::on_echButton1_clicked()
{
    if(!ui->checkBox->isChecked())
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
    a = a.echelon();

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
}

void MainWindow::on_echButton2_clicked()
{
    if(!ui->checkBox->isChecked())
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
    b = b.echelon();

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
}

void MainWindow::on_trButton1_clicked()
{
    if(!ui->checkBox->isChecked())
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
    a = a.tr();

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
}

void MainWindow::on_trButton2_clicked()
{
    if(!ui->checkBox->isChecked())
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
    b = b.tr();

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
}

void MainWindow::on_adjButton1_clicked()
{
    if(!ui->checkBox->isChecked())
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
    a = a.adj();

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
}

void MainWindow::on_adjButton2_clicked()
{
    if(!ui->checkBox->isChecked())
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
    b = b.adj();

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
}


void MainWindow::on_insertLeft_clicked()
{
    if(!ui->checkBox->isChecked())
    {
        std::vector<fraction> f_vectorA;
        std::vector<fraction> f_vectorA2;

        std::vector<std::string> s_vectorA(9, "");
        std::vector<std::string> s_vectorA2;

        s_vectorA[0] = ui->resultBox1->displayText().toStdString();
        s_vectorA[1] = ui->resultBox2->displayText().toStdString();
        s_vectorA[2] = ui->resultBox3->displayText().toStdString();
        s_vectorA[3] = ui->resultBox4->displayText().toStdString();
        s_vectorA[4] = ui->resultBox5->displayText().toStdString();
        s_vectorA[5] = ui->resultBox6->displayText().toStdString();
        s_vectorA[6] = ui->resultBox7->displayText().toStdString();
        s_vectorA[7] = ui->resultBox8->displayText().toStdString();
        s_vectorA[8] = ui->resultBox9->displayText().toStdString();


        f_vectorA = string_to_fraction(s_vectorA);

        matrix a(f_vectorA, 3, 3);

        f_vectorA2 = a.matrix_to_vector();
        s_vectorA2 = fraction_to_string(f_vectorA2);

        ui->inputBox1->setText(QString::fromStdString(s_vectorA2[0]));
        ui->inputBox2->setText(QString::fromStdString(s_vectorA2[1]));
        ui->inputBox3->setText(QString::fromStdString(s_vectorA2[2]));
        ui->inputBox4->setText(QString::fromStdString(s_vectorA2[3]));
        ui->inputBox5->setText(QString::fromStdString(s_vectorA2[4]));
        ui->inputBox6->setText(QString::fromStdString(s_vectorA2[5]));
        ui->inputBox7->setText(QString::fromStdString(s_vectorA2[6]));
        ui->inputBox8->setText(QString::fromStdString(s_vectorA2[7]));
        ui->inputBox9->setText(QString::fromStdString(s_vectorA2[8]));

    }
}
void MainWindow::on_insertRight_clicked()
{
    if(!ui->checkBox->isChecked())
    {
        std::vector<fraction> f_vectorB;
        std::vector<fraction> f_vectorB2;

        std::vector<std::string> s_vectorB(9, "0");
        std::vector<std::string> s_vectorB2;

        s_vectorB[0] = ui->resultBox1->displayText().toStdString();
        s_vectorB[1] = ui->resultBox2->displayText().toStdString();
        s_vectorB[2] = ui->resultBox3->displayText().toStdString();
        s_vectorB[3] = ui->resultBox4->displayText().toStdString();
        s_vectorB[4] = ui->resultBox5->displayText().toStdString();
        s_vectorB[5] = ui->resultBox6->displayText().toStdString();
        s_vectorB[6] = ui->resultBox7->displayText().toStdString();
        s_vectorB[7] = ui->resultBox8->displayText().toStdString();
        s_vectorB[8] = ui->resultBox9->displayText().toStdString();


        f_vectorB = string_to_fraction(s_vectorB);

        matrix a(f_vectorB, 3, 3);

        f_vectorB2 = a.matrix_to_vector();
        s_vectorB2 = fraction_to_string(f_vectorB2);

        ui->inputBox1_2->setText(QString::fromStdString(s_vectorB2[0]));
        ui->inputBox2_2->setText(QString::fromStdString(s_vectorB2[1]));
        ui->inputBox3_2->setText(QString::fromStdString(s_vectorB2[2]));
        ui->inputBox4_2->setText(QString::fromStdString(s_vectorB2[3]));
        ui->inputBox5_2->setText(QString::fromStdString(s_vectorB2[4]));
        ui->inputBox6_2->setText(QString::fromStdString(s_vectorB2[5]));
        ui->inputBox7_2->setText(QString::fromStdString(s_vectorB2[6]));
        ui->inputBox8_2->setText(QString::fromStdString(s_vectorB2[7]));
        ui->inputBox9_2->setText(QString::fromStdString(s_vectorB2[8]));

    }
}

void MainWindow::on_clearButton1_clicked()
{
    ui->inputBox1->setText(QString::fromStdString("0"));
    ui->inputBox2->setText(QString::fromStdString("0"));
    ui->inputBox3->setText(QString::fromStdString("0"));
    ui->inputBox4->setText(QString::fromStdString("0"));
    ui->inputBox5->setText(QString::fromStdString("0"));
    ui->inputBox6->setText(QString::fromStdString("0"));
    ui->inputBox7->setText(QString::fromStdString("0"));
    ui->inputBox8->setText(QString::fromStdString("0"));
    ui->inputBox9->setText(QString::fromStdString("0"));
}
void MainWindow::on_clearButton2_clicked()
{
    ui->inputBox1_2->setText(QString::fromStdString("0"));
    ui->inputBox2_2->setText(QString::fromStdString("0"));
    ui->inputBox3_2->setText(QString::fromStdString("0"));
    ui->inputBox4_2->setText(QString::fromStdString("0"));
    ui->inputBox5_2->setText(QString::fromStdString("0"));
    ui->inputBox6_2->setText(QString::fromStdString("0"));
    ui->inputBox7_2->setText(QString::fromStdString("0"));
    ui->inputBox8_2->setText(QString::fromStdString("0"));
    ui->inputBox9_2->setText(QString::fromStdString("0"));
}

void MainWindow::on_gradButton1_clicked()
{
    if(ui->checkBox->isChecked())
    {
    std::string funcA = ui->inputBox1->displayText().toStdString();
    std::vector<std::vector<int>> VVI = string_to_func(funcA);
    std::vector<std::vector<std::vector<int>>> grad(2);
    grad[0] = dif(VVI, 'x');
    grad[1] = dif(VVI, 'y');

    ui->resultBox1->setText(QString::fromStdString(func_to_string(grad[0])));
    ui->resultBox4->setText(QString::fromStdString(func_to_string(grad[1])));
    }
}


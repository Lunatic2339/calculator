#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "matrix.h"
#include "fraction.h"

#include <iostream>
#include <sstream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_inverseButton1_clicked();
    void on_plusButton_clicked();
    void on_minusButton_clicked();
    void on_mulButton_clicked();
    void on_inverseButton2_clicked();


private:
    Ui::MainWindow *ui;
    std::vector<std::string> s_vectorA;
    std::vector<std::string> s_vectorB;

};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Carr.h"
#include <QMainWindow>
#include <vector>
#include <iostream>
#include "csvread.h"
#include <fstream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
 //   void open();
 //   void find();

 //   void on_buttonfind_clicked();
    void on_bo_clicked();
    void on_button_add_clicked();
    //void findresults();
private slots:
    void on_buttonfind_clicked();


private:
    Ui::MainWindow *ui;
     std::vector<Car> cars;
     CsvReader reader;
};
#endif // MAINWINDOW_H

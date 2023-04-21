#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "csvread.h"
#include<iostream>
#include <vector>
#include <string>
#include <QFileDialog>
#include <fstream>
#include <Carr.h>
#include "csvwriter.h"
#include "customcolor.h"
#include <QFileInfo>
#include <algorithm>
//#include "abstractreader.h"
#include "jsonreader.h"
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

void MainWindow::on_bo_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(0, "Open File", "");
    QString filename=filePath;
    QFileInfo fi(filename.toLatin1().data());
    QString ext = fi.suffix();
    if(ext=="csv"){
        CsvReader csv;
    if (csv.open(filePath)){
        try{
        cars=csv.readAll();
        }
        catch (const error& e){
            ui->findresults<<QString::fromStdString("Line whith error:");
            ui->findresults<<QString::number(e.e_);
        }
        std::sort(cars.begin(),cars.end());

    }
    }
    if(ext=="json") {
        JsonReader jsn;
        if(jsn.open(filePath)){
        cars=jsn.readAll();
        std::sort(cars.begin(),cars.end());
        }
    }
}

void MainWindow::on_buttonfind_clicked()
{
    ui->editfind->text();
    bool flag = true;
    for(const auto &v: cars){
        if(ui->editfind->text().toStdString() == v.name){

            ui->findresults->appendGreen(QString::fromStdString(v.name) +','+QString::number(v.year));
            flag = false;
        }

    }
    if (flag) ui->findresults->appendPink("No cars");
    ui->editfind->clear();
}
void MainWindow::on_button_add_clicked()
{
    Car newData;
    newData.id=ui->id_add->text().toInt();
    newData.name=ui->model_add->text().toStdString();
    newData.rating=ui->year_add->text().toInt();
    newData.year=ui->rating_add->text().toInt();
    CSVWriter Write;
    if(newData.id< 10 && newData.name != "aboba")
    {
        cars.push_back(newData);
        Write.write(cars);
    }
    else {
        ui->findresults<<QString::fromStdString("data is unavalable:");
        std::cout<<newData;
    }
    ui->id_add->clear();
    ui->model_add->clear();
    ui->year_add->clear();
    ui->rating_add->clear();


}



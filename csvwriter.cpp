#include "csvwriter.h"
#include <vector>
#include <fstream>
#include <QString>
#include <string>
#include<iostream>
using std::vector;
CSVWriter::CSVWriter()
{

}
void CSVWriter::write(vector<Car> newData)
{
     std::ofstream fout;
     QString filename="test.csv";
     fout.open(filename.toLatin1().data());
     if (!fout.is_open()) {
       std::cout << "Error! File is not open" << std::endl;
     } else {
         for (int i = 0; i < int(newData.size()); i++) {
           fout << (newData[i]).id << (newData[i]).name << (newData[i]).rating<<(newData[i]).year<< std::endl;
         }
     }
     fout.close();
}

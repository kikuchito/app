#ifndef CSVREADER_H
#define CSVREADER_H
#include "abstractreader.h"
#include <string>
#include <vector>
#include "Carr.h"
#include <fstream>
#include <QString>
#include <iostream>
 using std::string;
 using std::vector;
struct error : std::exception {
    error(int e) : e_{e} {}

     int e_;
};
class CsvReader: public AbstractReader
{
public:
    CsvReader(){};
    bool open(const QString& fname) override;
    bool is_open()  const override  {return fin.is_open();}
    vector<Car> readAll() override;
    std::ifstream fin;

};


#endif // CSVREADER_H

#ifndef CSVWRITER_H
#define CSVWRITER_H
#include <string>
#include <vector>
#include "Carr.h"
#include <fstream>
#include <QString>
using std::vector;
class CSVWriter
{
public:
    CSVWriter();
    //void write(vector<Car> cars, Car newData);
    void write(vector<Car> newData);
};



#endif // CSVWRITER_H

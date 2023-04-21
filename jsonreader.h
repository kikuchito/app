#ifndef JSONREADER_H
#define JSONREADER_H
#include "abstractreader.h"
#include <string>
#include <vector>
#include "Carr.h"
#include <fstream>
#include <QString>
using std::vector;
class JsonReader:public AbstractReader
{
public:
    JsonReader(){};
    bool open(const QString& fname) override;
    bool is_open() const override  {return fin.is_open();}
    vector<Car> readAll() override;
    std::ifstream fin;
};

#endif // JSONREADER_H

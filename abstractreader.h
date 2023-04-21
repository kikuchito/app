#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H
#include <json.hpp>
#include <fstream>
#include <QString>
#include <string>
#include <vector>
#include "Carr.h"
//using json = nlohmann::json;

class AbstractReader
{
public:

    virtual std::vector<Car> readAll()=0;
    virtual bool is_open() const =0;
    virtual bool open(const QString& fname)=0;
    std::ifstream fin;
    ~AbstractReader() = default;
};

#endif // ABSTRACTREADER_H

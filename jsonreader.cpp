#include "jsonreader.h"
#include <Carr.h>
#include <fstream>
#include "abstractreader.h"
#include <json.hpp>
#include <iostream>
using json = nlohmann::json;
using std::vector;

bool JsonReader::open(const QString& fname)
{
     fin.open(fname.toLatin1().data());
     return fin.is_open();
}
vector<Car> JsonReader::readAll(){
    //std::ifstream fin("example.json");
    //json data = json::parse(fin);
    vector<Car> cars;
     nlohmann::json json;
    fin>>json;
    for(const auto & j: json) {
         Car c;
         //c.id = static_cast<int>(...)
         c.id=(j["id"]);
         c.name=(j["name"]);
         c.rating=(j["rating"]);
         c.year=(j["year"]);
         cars.push_back(c);
    }
    return cars;


}

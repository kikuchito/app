#include "csvread.h"
#include <Carr.h>
#include <fstream>
#include "abstractreader.h"

 bool CsvReader::open(const QString& fname)
 {
      fin.open(fname.toLatin1().data());
      return fin.is_open();
 }
 vector<string> split(const string& str, char delim)
 {
     vector<string> tokens;

     if (!str.empty())
     {
         size_t start = 0, end;
         do {

             end = str.find(delim, start);
             tokens.push_back(str.substr(start, (end - start)));
             start = end + 1;
         } while (end != string::npos);
     }

     return tokens;
 }



vector<Car> CsvReader::readAll()
{
    vector<Car> cars;
    int k=0;

    while (!fin.eof()){

        string str;
        getline(fin,str);
        auto tokens=split(str,',');
        if (tokens.size() != 4)
            throw error(k);
        Car c;
        c.id=stoi(tokens[0]);
        c.name=tokens[1];
        c.year=stoi(tokens[2]);
        c.rating=stoi(tokens[3]);
       cars.push_back(c);
       k++;


}


    return cars;
}


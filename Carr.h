#ifndef CARR_H
#define CARR_H
#ifndef CAR_H
#define CAR_H
#include <string>
#include <fstream>
using std::string;

struct Car{
    int id;
    string name;
    int year;
    int rating;
    bool operator < (const Car c)
    {
        if (id<c.id && year<c.year && rating<c.rating )
            return true;
        else
            return false;
    }
    bool operator == (const Car c)
    {
        if (name==c.name)
            return true;
        else
            return false;
    }
    friend std::ostream& operator << (std::ostream& os,const Car& c)
    {
        os << c.id<<","<<c.name<<std::endl;
        return os;
    }
};
#endif // CAR_H

#endif // CARR_H

#ifndef Project_businessobject_TableUnit_H_//sub class of all table
#define Project_businessobject_TableUnit_H_

#include "../libs/json.hpp"
#include <string>
#include <iostream>

using namespace std;
using json = nlohmann::json;

class TableUnit{
private:
public:
    TableUnit();
    TableUnit(json j);
    int Id;
    //TableUnit();
    int GetID();
    virtual string ToString() = 0;
    virtual json ToJson() = 0;
    //virtual TableUnit* FromJson(json) = 0;
    virtual void FromJson(json) = 0;
};

#endif
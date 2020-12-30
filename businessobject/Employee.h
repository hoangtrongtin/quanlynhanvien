#ifndef Project_businessobject_Employee_H_
#define Project_businessobject_Employee_H_

#include <string>
#include "../libs/json.hpp"
#include "TableUnit.h"

using namespace std;
using json = nlohmann::json;

class Employee: public TableUnit{
public:// private:
    //int Id; // id is increasing number
    string FName, MInit, LName;
    long SSN;
    string BDate, Address;
    char Sex;
    int Salary;
    long SuperSSN;
    int DNO;

public:
    Employee();
    Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno);
    Employee(json j);
    //int GetID();
    string ToString();
    json ToJson();
    void FromJson(json);
    TableUnit *NewPoint();
};

#endif

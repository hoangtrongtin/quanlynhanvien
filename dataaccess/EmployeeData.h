#ifndef Project_dataaccess_Employee_Data_H_
#define Project_dataaccess_Employee_Data_H_
#include <vector>
#include <string>
#include "../businessobject/Employee.h"
#include "TableData.h"

class EmployeeData: public TableData{
private:
    // vector<Employee> _data;
    // int _maxId;
public:
    EmployeeData();
    EmployeeData(string);
    // int GetMaxID();
    //int PushBack(Employee);
    //int Get(int i);///
    //Employee* GetPointer(int i);
    //string ToString();
    //EmployeeData GenerateData();//
    //int ExportToFile(string);

};
#endif

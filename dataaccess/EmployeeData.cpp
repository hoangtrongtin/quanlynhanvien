#include "EmployeeData.h"
#include <fstream>
#include <string>
#include "../libs/json.hpp"

using json = nlohmann::json;

EmployeeData::EmployeeData() : TableData(){}
EmployeeData::EmployeeData(string filename){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        json j = json::parse(buff);
        //cout << typeid(j["Sex"]).name() <<endl;
        Employee* e = new Employee(
            j["Id"],
            j["FName"],
            j["MInit"],
            j["LName"],
            j["SSN"],
            j["BDate"],
            j["Address"],
            (char) ((int) j["Sex"]),
            j["Salary"],
            j["SuperSSN"],
            j["DNO"]
        );
        _data.push_back(e);
    }
    inFile.close();
}
// int EmployeeData::GetMaxID(){
//     return _maxId;
// }
// int EmployeeData::PushBack(Employee e){
//     if(_maxId<e.GetID()){
//         _maxId = e.GetID();
//     }
//     _data.push_back(e);
//     return _maxId;
// }
//int EmployeeData::Get(int i){}
// Employee* EmployeeData::GetPointer(int i){
//     Employee *e = nullptr;
//     if(i >=0 && i<_data.size())
//     e = &_data[i];
//     return e;
// }
// string EmployeeData::ToString()
// {
//     string s("");
//     for(auto e:_data)
//     {
//         s += e.ToString();
//         s += "\n";
//     }
//     return s;
// }
/*EmployeeData EmployeeData::GenerateEmployeeData()
{
    //Employee e(1, "Chau", "Bao", "Ngo", 111222333, "1975-04-30", "Chicago", 'M', 10000, -1, 5);
    Employee e1(1, "John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee e2(2, "franklin", "T", "Wong", 333445555, "1955-12-08", "638 Voss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee e3(3, "Alicia", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring, TX", 'F', 25000, 987654321, 4);
    Employee e4(4, "Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry, Bellaire, TX", 'F', 43000, 888665555, 4);
    Employee e5(5, "Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Humble, TX", 'M', 38000, 333445555, 5);
    Employee e6(6, "Joyce", "A", "English", 453453453, "1972-07-31", "5631 Ric, Houston, TX", 'F', 25000, 333445555, 5);
    Employee e7(7, "Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas, Houston, TX", 'M', 25000, 987654321, 4);
    Employee e8(8, "James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    EmployeeData employeedata;
    employeedata.PushBack(e1);
    employeedata.PushBack(e2);
    employeedata.PushBack(e3);
    employeedata.PushBack(e4);
    employeedata.PushBack(e5);
    employeedata.PushBack(e6);
    employeedata.PushBack(e7);
    employeedata.PushBack(e8);
    return employeedata;
    
}*////
// int EmployeeData::ExportToFile(string filename){
//     ofstream outFile(filename, ios::out);
//     if (!outFile) return 0;
//     for (Employee e:_data){
//         outFile << e.ToJson() << endl;
//     }
//     outFile.close();
//     return 1;
// }

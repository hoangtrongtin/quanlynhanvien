#include "Employee.h"
#include <string>
#include <iostream>

Employee::Employee(){};
Employee::Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno)
{
    this->Id = id;
    this->FName = fName;
    this->MInit = mInit;
    this->LName = lName;
    this->SSN = ssn;
    this->BDate = bDate;
    this->Address = address;
    this->Sex = sex;
    this->Salary = salary;
    this->SuperSSN = superSSN;
    this->DNO = dno;
}
Employee::Employee(json j): TableUnit (j){
    this->Id = j["Id"];
    this->FName = j["FName"];
    this->MInit = j["MInit"];
    this->LName = j["LName"];
    this->SSN = j["SSN"];
    this->BDate = j["BDate"];
    this->Address = j["Address"];
    this->Sex = (char) ((int) j["Sex"]);
    this->Salary = j["Salary"];
    this->SuperSSN = j["SuperSSN"];
    this->DNO = j["DNO"];
}
// int Employee::GetID(){
//     return Id;
// }
string Employee::ToString(){
    string s;
    s += "{";
    s += to_string(Id) + ", ";
    s += FName + ", " + MInit + ", " + LName + ", ";
    s += to_string(SSN) + ", ";
    s += BDate + ", " + Address + ", ";
    s += std::string(1, Sex) + ", ";
    s += to_string(Salary) + ", ";
    s += to_string(SuperSSN) + ", ";
    s += to_string(DNO);
    s += "}";
    return s;

}
json Employee::ToJson(){
    json j;
    j["Id"] = Id;
    j["FName"] = FName;
    j["MInit"] = MInit;
    j["LName"] = LName;
    j["SSN"] = SSN;
    j["BDate"] = BDate;
    j["Address"] = Address;
    j["Sex"] = Sex;
    j["Salary"] = Salary;
    j["SuperSSN"] = SuperSSN;
    j["DNO"] = DNO;
    return j;
}
void Employee::FromJson(json j){
    //TableUnit* tU = new Employee(
    // tU = new Employee(
    //     j["Id"],
    //     j["FName"],
    //     j["MInit"],
    //     j["LName"],
    //     j["SSN"],
    //     j["BDate"],
    //     j["Address"],
    //     (char) ((int) j["Sex"]),
    //     j["Salary"],
    //     j["SuperSSN"],
    //     j["DNO"]
    // );
    this->Id = j["Id"];
    this->FName = j["FName"];
    this->MInit = j["MInit"];
    this->LName = j["LName"];
    this->SSN = j["SSN"];
    this->BDate = j["BDate"];
    this->Address = j["Address"];
    this->Sex = (char) ((int) j["Sex"]);
    this->Salary = j["Salary"];
    this->SuperSSN = j["SuperSSN"];
    this->DNO = j["DNO"];
    //return tU;
}
TableUnit* Employee::NewPoint(){
    TableUnit *tU = new Employee();
    return tU;
}
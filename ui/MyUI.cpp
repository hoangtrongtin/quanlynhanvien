#include <string>
#include <iostream>
#include <fstream>
#include "MyUI.h"
//#include "../businessobject/TableUnit.h"
#include "../businessobject/TableUnit.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

MyUI::MyUI(){}
int MyUI::ExportToFile(TableData tD, string filename){
    ofstream outFile(filename, ios::out);
    if(!outFile) return 0;
    for (auto tU: tD.GetTableData()){
        outFile << tU->ToJson() <<endl;
    }
    outFile.close();
    return 1;
}
// TableData* MyUI::ImportFromFile(TableUnit* tU, string filename){
//     TableData *tD;
//     tD->SetMaxID(0);
//     tD->ReSize(0);
//     ifstream inFile(filename);
//     const int maxSize = 255;
//     char buff[maxSize];
//     while(inFile.getline(buff, maxSize))
//     {
//         json j = json::parse(buff);
//         tD->PushBack(tU->FromJson(j));
//     }
//     inFile.close();
//     return tD;
// }
//void MyUI::ImportFromFile(TableUnit* tU, TableData* tD, string filename){
void MyUI::ImportFromFile(TableUnit* tU, TableData* tD, string filename){
    tD->SetMaxID(0);
    tD->ReSize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    //vector <TableUnit*> _vtu;
    //_vtu = tD->GetTableData;
    while(inFile.getline(buff, maxSize))
    {
        json j = json::parse(buff);
        //TableUnit *tU = _vtu[0];
        tU->FromJson(j);
        tD->PushBack(tU);
    }
    inFile.close();
}
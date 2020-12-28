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
void MyUI::ImportFromFile(TableUnit* tU, TableData* tD, string filename){
    tD->SetMaxID(0);
    tD->ReSize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    cout<<"ImportFromFile3"<<endl;
    while(inFile.getline(buff, maxSize))
    {
        json j = json::parse(buff);
        cout<<"ImportFromFilewhile"<<endl;
        //TableUnit *tU;
        tU->FromJson(j);
        tD->PushBack(tU);
    }
    inFile.close();
    cout<<"ImportFromFile2"<<endl;
}
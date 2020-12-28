#include "TableData.h"
#include <iostream>

using json = nlohmann::json;

TableData::TableData(){
    _maxId = 0;
    _data.resize(0);
}
int TableData::GetMaxID(){
    return _maxId;
}
void TableData::SetMaxID(int i){
    _maxId = i;
    std::cout<<"ImportFromFile2"<<endl;
}
vector <TableUnit*> TableData::GetTableData(){
    return _data;
}
void TableData::ReSize(int n){
    _data.resize(n);
}
int TableData::PushBack(TableUnit* tU){
    if(_maxId < tU->GetID()){
        _maxId = tU->GetID();
    }
    _data.push_back(tU);
    return _maxId;
    
}
int TableData::PushBack(TableUnit* tU, json j){
    //TableUnit* tU;
    //tU->FromJson(tU, j);
    std::cout<< "json = " << j <<endl;
    
    tU->FromJson(j);

    if(_maxId < tU->GetID()){
        _maxId = tU->GetID();
    }
    _data.push_back(tU);
    return _maxId;
}
TableUnit* TableData::GetPointer(int i){
    TableUnit* tU = nullptr;
    if(i >= 0 && i < _data.size()) tU = _data[i];
    return tU;
}
string TableData::ToString(){
    string s("");
    for (auto d:_data){
        s += (*d).ToString();
        s += "\n";
    }
    return s;
}
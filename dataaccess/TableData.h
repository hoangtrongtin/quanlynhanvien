#ifndef Project_dataaccess_TableData_H_
#define Project_dataaccess_TableData_H_
#include <vector>
#include <string>
#include "../businessobject/TableUnit.h"

class TableData{
protected:
    vector <TableUnit*> _data;
    int _maxId;
public:
    TableData();
    int GetMaxID();
    void SetMaxID(int);
    vector <TableUnit*> GetTableData();
    void ReSize(int);
    int PushBack(TableUnit*);
    int PushBack(TableUnit*, json);
    //int Get(int i);
    TableUnit* GetPointer(int i);
    string ToString();
};

#endif
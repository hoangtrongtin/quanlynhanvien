#ifndef Project_ui_MyUI_H_
#define Project_ui_MyUI_H_
#include <string>
#include "../dataaccess/TableData.h"

using namespace std;

class MyUI{
private:
public:
    MyUI();
    //int ExportToFile(string filename);
    int ExportToFile(TableData tD, string filename);
    //TableData* ImportFromFile(TableUnit* tU, string filename);
    void ImportFromFile(TableUnit* tU, TableData* tD, string filename);///
};

#endif
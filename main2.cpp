#include <iostream>
#include <map>

using namespace std;

int main(){
    cout << "hello";
    map<string, string> dictionary;
    dictionary["id"] = "hehe";
    cout << *dictionary;
    return 0;
}
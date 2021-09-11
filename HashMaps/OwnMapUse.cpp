#include <iostream>
#include "OwnMap.h"
using namespace std;

int main(){
    OwnMap<int> map;

    for (int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }

    cout << map.size() << endl;

    map.remove("abc8");
    map.remove("abc9");
    for (int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key += c;

        cout << key << ":" << map.getValue(key) << endl;
    }

    cout << map.getValue("abc8") << endl;
    cout << map.getValue("abc9") << endl;
    cout << map.size() << endl;
    
    return 0;
}
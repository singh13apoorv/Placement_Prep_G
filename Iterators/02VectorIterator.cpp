#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);

    vector<int>::iterator it = v.begin();

    while (it != v.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;

    return 0;
}
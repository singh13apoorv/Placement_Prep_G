#include <bits/stdc++.h>
//#include <vector>
using namespace std;

int main(){
    vector<int> v;  //Statically creating vectors
    //vector<int> * v2 = new vector<int>(); Dynamically created vector

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    v.push_back(40);

    cout << "Size: " << v.size() << endl;

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    v.pop_back(); //used to delete last element from the vector
    //v.capacity() gives the capacity of the underlying array

    cout << v.at(0) << endl;  //at is always safer to use as compared to []
    cout << v.at(1) << endl;
    cout << v.at(2) << endl;

    return 0;
}
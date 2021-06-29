#include <iostream>
using namespace std;

int main(){
    int N, i, j, k, l;
    cin >> N;
    
    for (i = 0; i <= N/2; i++){
        for (j = (N/2 - i); j > 0; j--){
            cout << " ";
        }
        
        for (k = 0; k < i + 1; k++){
            cout << "*";
        }
        
        for (l = 0; l < i; l++){
            cout << "*";
        }
        cout << endl;
    }
    
    for (i = N/2; i > 0; i--){
        for (j = (N/2 - i + 1); j > 0; j--){
            cout << " ";
        }
        
        for (k = 0; k < i; k++){
            cout << "*";
        }
        
        for (l = i - 1; l > 0; l--){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
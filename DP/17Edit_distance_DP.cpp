#include <iostream>
#include <string>
using namespace std;

int editDistance(string s, string t){
    int m = s.size();
    int n = t.size();

    int **output = new int*[m + 1];
    for (int i = 0; i <= m; i++){
        output[i] = new int[n + 1];
    }

    //for 1st row
    for (int j = 0; j <= n; j++){
        output[0][j] = j;
    }

    //for 1st column
    for (int i = 1; i <= m; i++){
        output[i][0] = i;
    }

    //across
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s[m - i] == t[n - j]){
                output[i][j] = output[i - 1][j - 1];
            }
            else {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];

                output[i][j] = 1 + min(a, min(b, c));
            }
        }
    }

    return output[m][n];
}

int main(){
    string s;
    string t;

    cout << "Enter string 1st: ";
    cin >> s;

    cout << "Enter string 2nd: ";
    cin >> t;

    cout << "Edit distance of " << s << " and " << t << " is: " << editDistance(s, t) << endl;

    return 0;
}
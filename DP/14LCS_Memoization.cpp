#include <iostream>
#include <string>
using namespace std;

int LCS_mem(string s, string t, int **output){
    if (s.size() == 0 || t.size() == 0){
        return 0;
    }

    if (output[s.size()][t.size()] != -1){
        return output[s.size()][t.size()];
    }

    int ans;
    if (s[0] == t[0]){
        ans = 1 + LCS_mem(s.substr(1), t.substr(1), output);
    }
    else {
        int smallAns1 = LCS_mem(s.substr(1), t, output);
        int smallAns2 = LCS_mem(s, t.substr(1), output);

        ans = max(smallAns1, smallAns2);
    }

    output[s.size()][t.size()] = ans;

    return ans;
}

int LCS(string s, string t){
    int **output;
    output = new int*[s.size() + 1];

    for (int i = 0; i < s.size() + 1; i++){
        output[i] = new int[t.size() + 1];
        for (int j = 0; j <= t.size(); j++){
            output[i][j] = -1;
        }
    }

    return LCS_mem(s, t, output);
}

int main(){
    string s;
    string t;

    cout << "Enter string 1st: ";
    cin >> s;

    cout << "Enter string 2nd: ";
    cin >> t;

    cout << "LCS of " << s << " and " << t << " is: " << LCS(s, t) << endl;

    return 0;
}
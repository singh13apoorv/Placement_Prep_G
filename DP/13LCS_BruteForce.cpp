#include <iostream>
#include <string>
using namespace std;

int LCS(string s, string t){
    if (s.size() == 0 || t.size() == 0){
        return 0;
    }

    if (s[0] == t[0]){
        return 1 + LCS(s.substr(1), t.substr(1));
    }
    else {
        int smallAns1 = LCS(s.substr(1), t);
        int smallAns2 = LCS(s, t.substr(1));

        return max(smallAns1, smallAns2);
    }
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
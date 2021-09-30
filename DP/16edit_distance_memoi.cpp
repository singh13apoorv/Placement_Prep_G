#include <iostream>
#include <string>
using namespace std;

int helper(string s, string t, int **output){
    if (s.size() == 0 || t.size() == 0){
        return max(s.size(), t.size());
    }

    int i = s.size();
    int j = t.size();

    if (output[i][j] != -1){
        return output[i][j];
    }

    int ans;
    if (s[0] == t[0]){
        ans = helper(s.substr(1), t.substr(1), output);
    }
    else {
        //insert
        int a = helper(s.substr(1), t, output);
        //delete
        int b = helper(s, t.substr(1), output);
        //discard both
        int c = helper(s.substr(1), t.substr(1), output);

        ans = min(a, min(b, c)) + 1;
    }
    output[i][j] = ans;

    return ans;
}

int editDistance(string s, string t){
    int m = s.size();
    int n = t.size();

    int **output = new int*[m + 1];
    for (int i = 0; i <= m; i++){
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++){
            output[i][j] = -1;
        }
    }

    return helper(s, t, output);
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
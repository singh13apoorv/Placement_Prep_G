#include <bits/stdc++.h>

int facto(int n)
{
    if(n == 0)
        return 1;
    int i = n, fact = 1;
    while (n / i != n) {
        fact = fact * i;
        i--;
    }
    return fact;
}

int returnPermutations(string input, string output[]){
    /* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if (input.size() == 1){
        output[0] = input[0];
        return 1;
    }
    
    int smallAns = returnPermutations(input.substr(1), output);

    int j = 0;
    for (int i = smallAns; i < facto(output[0].size() + 1); i++){
        output[i] = output[j];
        j++;
        if (j == smallAns){
            j = 0;
        }
    }
    
    int temp1 = output[0].size();
    int k = 0;
    int count = 0;
    for (int i = 0; i < facto(temp1 + 1); i++){
        string temp = output[i].substr(0, k);
        string o1 = output[i].substr(k);
        output[i] = temp + input[0] + o1;
        count++;
        if (count == facto(temp1)){
            k++;
            count = 0;
        }
    }
    
    
    return facto(output[0].size());
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

int Memoization(int n, int *ans){
    if (n == 1){
        return 0;
    }
    
    if (ans[n] != -1){
        return ans[n];
    }
    
    int way1 = Memoization(n - 1, ans);
    int way2 = INT_MAX;
    int way3 = INT_MAX;
    
    if (n % 2 == 0){
        way2 = Memoization(n / 2, ans);
    }
    if (n % 3 == 0){
        way3 = Memoization(n / 3, ans);
    }
    
    int output = 1 + min(way1, min(way2, way3));
    ans[n] = output;
    
    return ans[n];
}

int countMinStepsToOne(int n)
{
	//Write your code here
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    
    int output = Memoization(n, ans);
    
    return output;
}

int main()
{
	int n;

    cout << "Enter a number: ";
	cin >> n;

	cout << countMinStepsToOne(n) << endl;

    return 0;
}
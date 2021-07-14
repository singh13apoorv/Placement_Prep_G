#include <bits/stdc++.h>
using namespace std;

void arrange(int *arr, int n){

    int j = 0;
    for (int i = 1; i <= n; i++){
        if (i % 2 != 0){
            arr[j] = i;
            j++;
        }
    }

    
    for (int i = n; i >= 1; i--){
    	if (i % 2 == 0){
    		arr[j] = i;
    		j++;
    	}
    }
}

int main(){
	int t;
	cin >> t;

	while (t){
		int n;
		cin >> n;

		int arr[n];

		arrange(arr, n);

		for (int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;

		t--;
	}
	return 0;
}
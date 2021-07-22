#include <bits/stdc++.h>
using namespace std;

void Leaders(int* arr,int len)
{
    int i = 0;
    int j = i + 1;
    
    while (i < len){
        if (j == len){
            cout << arr[i] << " ";
            i++;
            j = i + 1;
            continue;
        }
        if (arr[i] < arr[j]){
            i++;
            j = i + 1;
            continue;
        }
        j++;
    }
}

int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
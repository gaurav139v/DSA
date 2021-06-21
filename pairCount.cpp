// Count paris with given sum O(n)
#include<bits/stdc++.h>

using namespace std;

int getPariCount(int arr[], int len, int k){
	int count = 0;
	map<int, int> m;
	
	for(int i=0; i<len; i++)
		m[arr[i]]++;
	
	
	for(int i=0; i<len; i++){
		count = count + m[k - arr[i]];
		
		if (k - arr[i] == arr[i])
			count--;
	}
	return count/2;
}

int main(){
	int arr[] = {1, 5, 7 ,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	int result = getPariCount(arr, len, 6);
	cout << result;
	return 0;
}
	

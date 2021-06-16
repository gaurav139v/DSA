//Minimise the maximum difference between heights [V.IMP] O(N*logN)
#include<bits/stdc++.h>

using namespace std;

int minimizeHeight(int arr[], int len, int k){
	sort(arr, arr + len);
	int mi, ma;
	int result = arr[len-1] - arr[0];
	
	for(int i=1; i<len; i++){
		if(k <= arr[i]){
			mi = min(arr[0] + k, arr[i] -k);
			ma = max(arr[len-1] - k, arr[i-1] + k);
			result = min(result, ma - mi);
		}
	}
	return result;
}

int main(){
	int n[] = {3,9,12,16,20}, k = 3;
	int len = sizeof(n)/sizeof(n[0]);
	int result = minimizeHeight(n, len, k);
	cout << result << endl;
}

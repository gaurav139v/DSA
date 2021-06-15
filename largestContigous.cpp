//find Largest sum contiguous Subarray [V. IMP] O(n).
#include<bits/stdc++.h>

using namespace std;

int largestSum(int arr[], int len){
	int sum = 0,best =0;
	for(int i=0; i<len; i++){
		sum = max(arr[i], sum + arr[i]);
		best = max(sum, best);
	}
	return best;
}

int main(){
	int arr[] = {2,3,-4,6,7,8,3,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	int sum = largestSum(arr,len);
	cout << sum << endl;
}

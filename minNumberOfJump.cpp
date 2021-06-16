// Minimum no. of Jumps to reach end of an array O(n^2).
// can be solved in O(N) need to find the solution.
#include<bits/stdc++.h>

using namespace std;

int getMinJump(int arr[], int len){
	int minSteps[len];
	minSteps[0] = 0;
	for(int i=1; i<len; i++){
		minSteps[i] = 10000001;
		for(int j=0; j<i; j++){
			if(arr[j] + j >= i){
				minSteps[i] = min(minSteps[i], minSteps[j] + 1);
			}
		}
	}
	if(minSteps[len-1] == 10000001)
		return -1; // when first element is 0
	return minSteps[len-1];
}

int main(){
	cout << INT_MAX;
	int arr[] = {1,3,5,8,9,2,6,7,6,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	int result = getMinJump(arr, len);
	cout << result << endl;
	return 0;
}

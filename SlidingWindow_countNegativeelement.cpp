// https://www.geeksforgeeks.org/count-negative-elements-present-in-every-k-length-subarray/
#include<bits/stdc++.h>
using namespace std;

void findNegativeInSubarray(int arr[], int len, int k){
	int start = 0, end= 0;
	int sum= 0;
	
	for(end=0; end< k; end++){
		if(arr[end] < 0)
			sum++;
	}
	cout << sum << " " ;
	
	for(int i = end; i< len; i++){
		if(arr[i] < 0) sum++;
		
		if(arr[start++] < 0) sum--;
		cout << sum << " " ;
	}
}


void findNegativeInSubarray1(int arr[], int len, int k){
	int start = 0, end= 0;
	int sum= 0;
	
	while(end< len){
		if(arr[end] < 0)
			sum++;
		
		if(end == k) cout << sum << " " ;
		
		if((end++ >= k)){			
			if((arr[start++] < 0))
				sum--;
			cout << sum << " " ;
		}
	}	
}



int main(){
	int arr[] = {-1, 2, -2, 3, 5, -7, -5};
	int k = 3;
	int len = sizeof(arr)/sizeof(arr[0]);
	
	findNegativeInSubarray(arr, len, k);
	cout << endl;
	findNegativeInSubarray1(arr, len, k);
	
}

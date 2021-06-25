// Smallest Subarray with sum greater than a given value O(n)
#include<bits/stdc++.h>
using namespace std;

int findResult(int arr[] , int len, int sum){
	int start = 0, end = 0;
	int curSum = 0;
	int minLen = len + 1;
//	for(int i=0; i<len; i++){
	while(end < len){
		while(curSum <= sum && end < len)
			curSum += arr[end++];
		
	
		while(curSum > sum && start < len){
			if(end - start < minLen){
				minLen = end - start;
			}
			curSum -= arr[start++];
			
		}
	}
	return minLen;
		
}



int main(){
	int arr[] ={1, 3, 4, 7, 10, 10, 8, 10}; // { 15, 2, 4, 8, 9, 5, 10, 23 };
	int len = sizeof(arr)/sizeof(arr[0]);
	int sum = 10;
	int result = findResult(arr, len, sum);
	cout <<  result << endl;
}

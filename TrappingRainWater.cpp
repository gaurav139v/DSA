//Trapping Rain water problem
#include<bits/stdc++.h>

using namespace std;

// this solution take time complexity O(n^2) and space O(1)
int method1(int arr[] , int len){
	int result = 0;
	
	for(int i=0; i<len -1; i++){
		
		int left = arr[i];
		for(int j=0; j<i; j++){
			if(left < arr[j])
				left  = arr[j];
		}
		
		int right = arr[i];
		for(int j=i+1; j<len; j++){
			if(right < arr[j])
				right = arr[j];
		}
		int minHeight = min(left, right);
		result = result + minHeight - arr[i];
	}
	return result;
}

// this solution solve this problem in time complexity of O(n) and space complexity O(n)
int method2(int arr[], int len){
	// this uses dynamic programming to store the left and right max infomation to the array
	int left[len];
	int right[len];
	int result = 0;
	
	//int lo = arr[0];
	left[0] = arr[0];
	for(int i=1; i<len; i++){
		left[i] = max(left[i-1],arr[i]);
	}
	
	//int r = arr[len-1];
	right[len-1] = arr[len-1];
	for(int i=len-2; i>=0; i--){
		right[i] = max(right[i+1], arr[i]);
	}
	
	for(int i=0; i<len; i++){
		result = result + min(left[i], right[i]) - arr[i];
	}
	return result;
}
	
// This method uses time complextiy O(n) and space complexity O(1)
int method3(int arr[], int len){
	// In this we only use two variable to store the left and right min and max
	int lo = 0, r = len-1;
	
	int leftMax = 0, rightMax = 0;
	int result = 0;
	
	while(lo <= r){
		if(arr[lo] < arr[r]){
			if(arr[lo] > leftMax)
				leftMax = arr[lo];
			else
				result += leftMax - arr[lo];
			lo++;
		}else{
			if(arr[r] > rightMax)
				rightMax = arr[r];
			else
				result += rightMax - arr[r];
				r--;
		}
	}
	return result;
}
	
int main(){
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  //{8, 8, 2, 4, 5, 5, 1};
	int len = sizeof(arr)/sizeof(arr[0]);
	int result = method1(arr, len);
	cout << result << endl;
	result = method2(arr, len);
	cout << result << endl;
	
	result = method3(arr,len);
	cout << result << endl;
}

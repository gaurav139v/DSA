#include<bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int maxPage, int k,int len){
	int i = 0;
	int s = 0;
	int count = 1;
	
	while(i < len){
		s += arr[i];
		if(s > maxPage){
			count++;
			s = arr[i];
		}
		if(count > k)
			return false;
		i++;
	}
	return true;
}

int MinimizeMaxNoOfPage(int arr[], int len, int k){
	int end = 0; // sum of array
	int start = arr[0]; // max of array
	int result = -1;
	
	for(int i=0; i<len; i++){
		end += arr[i];
		if(start < arr[i]) 
			start = arr[i];
	}
	cout << end << " " << start << endl;
	
	while(start <= end){
		int mid = start + (end - start)/2;
		if(isValid(arr, mid, k, len)){
			result = mid;
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}
	return result;
}

int main(){
	int arr[] = {10,20,30,40};
	int len = sizeof(arr)/sizeof(arr[0]);
	int k = 2;
	int result = MinimizeMaxNoOfPage(arr, len, k);
	cout << "Result : " << result << endl;
}

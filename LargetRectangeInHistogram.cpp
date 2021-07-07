// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
#include<bits/stdc++.h>
using namespace std;

int findLargestArea(int arr[], int len){
	stack<int> s;
	int left[len], right[len];
	
	for(int i=0; i<len; i++){
		if(s.empty()){
			left[i]=0;
			s.push(i);
		}else{
			while(!s.empty() && arr[s.top()] >= arr[i])
				s.pop();
			left[i] = s.empty()? 0 : s.top() + 1;
			s.push(i);
		}		
	}
	
	while(!s.empty()){
		s.pop();
	}
	
	for(int i=len-1; i>=0; i--){
		if(s.empty()){
			s.push(i);
			right[i] = len-1;
		}else{
			while(!s.empty() && arr[i] < arr[s.top()])
				s.pop();
			right[i] = s.empty()? len-1 : s.top() -1;
			s.push(i);
		}
	}
	
	int maxValue = 0;
	for(int i=0; i<len; i++){
		maxValue = max(maxValue, (right[i] - left[i] + 1) * arr[i]);
	}
	return maxValue;	
}

int main(){
	int arr[] = {2,1,5,6,2,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	int result = findLargestArea(arr, len);
	cout << result << endl;
}

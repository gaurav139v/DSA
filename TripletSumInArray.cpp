// Find the triplet that sum to a given value time complexity O(N^2) and space complexity O(n)
#include<bits/stdc++.h>

using namespace std;

bool findTriplet(int arr[], int len , int x){
	set<int> s;
	int i;
	
	for(i=0; i<len; i++){
		int first = x - arr[i];
		for(int j=i; j< len; j++){
			s.insert(first - arr[j]);
		}
				
		for(int j=i+1; j<len; j++){
			if(s.find(arr[j]) != s.end() ){
				cout << arr[i] << " " << first -arr[j] << " " << arr[j] << endl;
				return true;
			}
		}
		s.clear();
	}
	return false;			
}

int main(){
	int n =6, x = 24;
	int arr[] = {12, 3, 4, 1, 6, 9};
	int len = sizeof(arr)/ sizeof(arr[0]);
	bool result = findTriplet(arr, len,x);
	if(result)
		cout << 1;
	else 
		cout << 0;
}

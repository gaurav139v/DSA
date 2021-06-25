// Find the triplet that sum to a given value time complexity O(N^2) and space complexity O(n)
#include<bits/stdc++.h>

using namespace std;

bool findTriplet(int arr[], int len , int x){
	vector<int> s;
	int i;
	
	for(i=0; i<len; i++){
		int first = x - arr[i];
		for(int j=i; j< len; j++){
			s.push_back(first - arr[j]);
		}
				
		for(int j=i+1; j<len; j++){
			auto temp = find(s.begin(),s.end(), arr[j]);
			cout << *temp << endl;
			if(temp != s.end() && arr[j] != *temp ){
				cout << arr[i] << " " << first -arr[j] << " " << arr[j] << endl;
				return true;
			}
		}
		s.clear();
	}
	return false;			
}

int main(){
	int  x = 9;
	int arr[] = {12, 3, 4, 1, 6, 9}; //{12, 3, 6, 8, 3, 9};
	int len = sizeof(arr)/ sizeof(arr[0]);
	bool result = findTriplet(arr, len,x);
	if(result)
		cout << 1;
	else 
		cout << 0;
}

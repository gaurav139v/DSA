// Chocolate Distribution problem O(n) && O(1)
#include<bits/stdc++.h>

using namespace std;

int findResult(vector<int> a, int n , int m){
	sort(a.begin() , a.end());	
	int minValue = INT_MAX;
	int len = n-m+1;
	
	for(int i=0; i<len; i++)	
		minValue = min(a[i+m-1] - a[i], minValue);
		
	return minValue;
}

int main(){
	vector<int> arr {34 ,88, 89, 39, 67, 71, 85, 57, 18, 7, 61, 50, 38, 6, 60, 18, 19, 46, 84, 74, 59}; //{3, 4, 1, 9, 56, 7, 9, 12};
	int len = arr.size();
	long long result = findResult(arr , len, 12);
	cout << result << endl;
}
	

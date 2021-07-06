// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
// time complexity O(m*n)
#include<bits/stdc++.h>
using namespace std;

int findResult(int arr[][4], int n, int m){
	int ma = -1;
	int result;
	
	for(int j=0; j<n; j++){
		int sum  = 0;
		
		for(int i=0; i<m; i++){
			sum += arr[j][i];
		}
		cout << sum  << " " << j << " " << ma << endl;
	   
	   if(sum > ma){
		   ma = sum;
		   result = j;
	   }
	}
	if(ma > 0) return result;	
	return -1;
}

// time complexity O(m+n)
int findReuslt1(int arr[][4], int n,int m){
	
	int j = m-1;
	int result = -1;
	int maxVal = m-1;
	
	for(int i=0; i<n; i++){
		while(j>=0 && arr[i][j] == 1) j--;
		
		if(maxVal > j){
			maxVal = j;
			result = i;
		}
	}
	return result;
}

int main(){
	int arr[4][4] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}};
    int n = 4, m = 4;
    int result = findResult(arr,n,m);
    cout << result << endl;
    
    result = findReuslt1(arr,n,m);
    cout << result << endl;
}

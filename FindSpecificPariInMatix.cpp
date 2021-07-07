// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
#include<bits/stdc++.h>
using namespace std;
#define MAX 5

void print(int temp[][MAX],int len){
	for(int i=0; i<len; i++){
		for(int j =0; j<len; j++){
			cout << temp[i][j] << "\t";
		}
		cout << endl;
	}
}

int findResult(int arr[][MAX], int len){
	int temp[MAX][MAX] ={0};
	temp[len-1][len-1] = arr[len-1][len-1];
	for(int i=len-2; i>=0; i--){
		temp[len-1][i] = max(arr[len-1][i], temp[len-1][i+1]);
		temp[i][len-1] = max(arr[i][len-1], temp[i+1][len-1]);
	}
	
	int maxDiff = INT_MIN;
	for(int i=len-2; i>=0; i--){
		for(int j=len-2; j>=0; j--){
			maxDiff = max(maxDiff , temp[i+1][j+1] - arr[i][j]);
			int test = max(temp[i][j+1], temp[i+1][j]);
			temp[i][j] = max(test, arr[i][j]);
		}	
	}
	return maxDiff;
}

int main(){
	int n  = 5;
	int arr[5][5]= {{ 1, 2, -1, -4, -20 },
					 { -8, -3, 4, 2, 1 }, 
					 { 3, 8, 6, 1, 3 },
					 { -4, -1, 1, 7, -6 },
					 { 0, -4, 10, -5, 1 }};
	int result = findResult(arr, n);
	cout << result << endl;
}	 
					 

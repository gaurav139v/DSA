// https://leetcode.com/problems/search-a-2d-matrix/ O(logN)
#include<bits/stdc++.h>
using namespace std;

int findResult(int matrix[][4], int col, int row ,int target){
	int mid;
	int totalElem = col * row;
	int start = 0, end =  totalElem -1;
	while(start <= end){
		mid = start + (end - start)/2;		
		int i = mid/col;
		int j = mid % col;
		if(matrix[i][j] == target) return matrix[i][j];
		
		if(target > matrix[i][j]) start = mid +1 ;
		else if (target < matrix[i][j]) end = mid -1;		
	}
	return false;
}

int main(){
	int matrix[3][4] = {{1, 3, 5, 7},
           {10, 11, 16, 20},
           {23, 30, 34, 60}}; 
           
    int col = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int row = sizeof(matrix)/sizeof(matrix[0]);
    int target = 6;
    bool result = findResult(matrix, col, row, target);
    cout << result << endl;
}

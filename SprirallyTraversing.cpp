// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#
#include<bits/stdc++.h>
using namespace std;

void print(int result[], int len){
	for(int i=0; i< len; i++)
		cout << result[i] << " ";
}

void findResult(int matrix[][4], int row, int col){
	int i=0, j = 0;
	int first = 0, second=0;
	
	while(row > first && col > second){
		
		for(; j < col; j++)
			cout <<  matrix[i][j] << " ";
		j--;
		
		for(i++; i < row; i++)
			cout <<  matrix[i][j] << " ";		
		i--;
		
		for(j--; j>=second; j--)
			cout << matrix[i][j] << " ";
		j++;
		
		for(i--; i>=first+1; i--)
			cout << matrix[i][j] << " ";
		
	
		i++;
		j++;
		first++;
		second++;
		row--;
		col--;
	}
}

int main(){
	int matrix[3][4] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}; 
    int col = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int row = sizeof(matrix)/sizeof(matrix[0]);
    findResult(matrix, row, col);
}

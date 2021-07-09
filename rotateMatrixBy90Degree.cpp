#include<bits/stdc++.h>
using namespace std;
#define N 4
#define M 4

void print(int arr[N][M]){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << arr[i][j] << "\t";
		}
		cout<< endl;
	}
}

void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void rotate90Degree(int arr[N][M]){
	// transpose the matrix
	for(int i=0; i<N; i++){
		for(int j=i+1; j<M; j++){
			swap(&arr[i][j], &arr[j][i]);
			cout << arr[i][j] << " " <<  arr[j][i] << endl;
		}
	}
	print(arr);
	cout<< endl;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M/2; j++){
			swap(&arr[i][j], &arr[i][M-j-1]);
		}
	}	
	
	
}

int main(){
	int arr[N][M] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8},
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Degree(arr);
    print(arr);
}

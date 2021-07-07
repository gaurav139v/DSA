//https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1# O(N^2LogN)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
	// code here
	int temp[N*N];
	int k = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			temp[k++] = Mat[i][j];
		}
	}
	
	sort(temp ,  temp+N*N);
	k = 0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			Mat[i][j] = temp[k++];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
				cout << Mat[i][j] << " ";
		}
		cout<< endl;
	}
	return Mat;
}
    
int  main(){
	vector<vector<int>> v {{10,20,30,40},
							{15,25,35,45},
							{27,29,37,48} ,
							{32,33,39,50}};
	int len = 16; 
	
	v = sortedMatrix(len, v);
	
}

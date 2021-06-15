#include<iostream>

using namespace std;

void swap(int *first, int *second){
	int val = *first;
	*first = *second;
	*second = val;
}

int main(){
	int num[] = {1,2,3, 4,5,6,7};
	int i = 0, j;
	int length = sizeof(num)/sizeof(num[0]);
	for(i=0,j = length-1; i< j; i++,j--){
		swap(&num[i],&num[j]);
	}
	
	for(auto a : num){
		cout << a << " ";
	}
	return 0;
}

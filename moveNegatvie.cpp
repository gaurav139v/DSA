// Move all the negative elements to one side of the array  [complexity = O(n)]
#include<iostream>

using namespace std;

void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void moveNegative(int n[], int len){
	int temp = 0;
	for(int i=0; i<len; i++){
		if(n[i] < 0){ 
			swap(&n[i], &n[temp]);
			temp++;
		}
	}
}

int main(){
	int n[] = {-3,3,45,-4,8,-1, -49};
	int len = sizeof(n)/sizeof(n[0]);
	moveNegative(n, len);
	for (auto a: n){
		cout << a << " ";
	}
}

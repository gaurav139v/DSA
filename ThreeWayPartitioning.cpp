// Three way partitioning of an array around a given value
#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int len){
	for(int i=0; i<len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int *first, int *second){
	int t = *first;
	*first = *second;
	*second = t;
}

void findResult(int arr[], int len, int a, int b){
	int start = 0, end= len-1;
	
	for(int i=0; i<=end;){
		
		if(arr[i] < a)	
			swap(&arr[i++], &arr[start++]);
		
		else if (arr[i] > b)
			swap(&arr[i] , &arr[end--]);
		else 
			i++;
	}

}

int main(){
	int arr[] = {2,33,3,1,4,6,8,5, 9};
	int len = sizeof(arr)/sizeof(arr[0]);
	int a = 4, b = 6;
	findResult(arr, len, a, b);
	print(arr, len);
}

//Write a program to cyclically rotate an array by one. O(n)
#include<iostream>

using namespace std;

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void rotate(int arr[], int n)
{	
	for(int i=1; i<n; i++){
        swap(&arr[0], &arr[i]);
    }
}

int main(){
	int arr[] = {1,2,3,4,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	rotate(arr, len);
	
	for(auto a: arr)
		cout << a << " ";
	return 0;
}

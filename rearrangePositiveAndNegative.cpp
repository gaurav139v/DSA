// Rearrange the array in alternating positive and negative items with O(1) extra space time Complexity O(n)
#include<bits/stdc++.h>

using namespace std;

void swap(int *first, int *second){
	int t = *first;
	*first = *second;
	*second = t;
}

void arrange(int arr[], int len){
	int odd = 1, even = 0;
	while(odd < len && even < len){
		if(arr[even] < 0){
			even += 2;
		}else{
			swap(&arr[even], &arr[odd]);
			odd += 2;
		}
	}
	
	int t=odd+2;
	while(t < len){
		t = odd + 2;
		if(arr[odd] > 0){
			odd += 2;
		}
		else{
			swap(&arr[odd], &arr[t]);
			t += 2;
		}
	}
	
	t = even+2;
	while(t < len){
		t = even + 2;
		if(arr[even] <0){
			even += 2;
		}else {
			swap(&arr[even] , &arr[t]);
			t += 2;
		}
	}
}

int main(){
	int arr[] = {-5, -2, 5, 2, -4, 7, -1, -8, 0, -8};
	int len = sizeof(arr)/sizeof(arr[0]);
	arrange(arr, len);
	for(auto a: arr)
		cout << a << " ";
}

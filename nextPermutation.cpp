// Next Permutation time complexity O(n) space complexity O(1)
#include<bits/stdc++.h>

using namespace std;

void swap(int *first, int *second){
	int t = *first;
	*first = *second;
	*second = t;
}	

void rev(int n[], int start, int end){
	while(start < end)
		swap(&n[start++] , &n[end--]);
}

int* nextPermutation(int n[], int len){
	int i = len-2, j = len-1;
	while(i >= 0 && n[i] >= n[i+1]) i--;
	while(j >= i && n[i] > n[j]) j--;
	swap(&n[i] , &n[j]);
	rev(n, i+1, len-1);
	return n;
}
	
int main(){
	int n[] {1};
	int len = sizeof(n)/sizeof(n[0]);
	nextPermutation(n, len);
	for(auto a: n)
		cout << a << " ";
}
	

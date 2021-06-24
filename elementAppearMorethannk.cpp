//Given an array of size n and a number k, fin all elements that appear more than " n/k " times.
#include<bits/stdc++.h>

using namespace std;

void findArray(int a[], int len, int x){
	map<int , int> s;
	for(int i=0; i<len; i++){
		s[a[i]]++;
	}
	
	for(auto i: s){
		if(i.second > x)
			cout << i.first << " ";
	}
}

int main(){
	int a[] = {3, 1, 2, 2, 1, 2, 3, 3};
	int k=4;
	int len = sizeof(a)/sizeof(a[0]);
	findArray(a, len, len/k);
	
}

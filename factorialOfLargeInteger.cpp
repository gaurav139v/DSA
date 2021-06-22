// Find factorial of a large number
#include<bits/stdc++.h>

using namespace std;

void display(int n[], int len){
	for(int i=len; i>=0; i--)
		cout << n[i] << " ";
}

int multiplay(int n[], int digit, int len){
	int carry = 0;
	int val;
	int i=0;
	
	for(i=0; i< len; i++){
		val = digit * n[i] + carry;
		carry = 0;
		n[i] = val % 10;
		val = (int)val/10;
		carry = carry + val;
	}

	while(val > 0){
		n[i++] = val % 10;
		val = (int)val/10;
	}
	return i;
}

int findFact(int n[], int num){
	int end=1;
	
	for(int i=2; i<=num; i++){
		end = multiplay(n, i, end);
	}
	
	return end-1;
}	

int main(){
	int num = 1000;
	int n[3000]={1};
	int end = findFact(n, num);
	display(n, end);
}

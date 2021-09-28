#include<bits/stdc++.h>
using namespace std;

int main(){
	char c[] = {'a','d','d','a','t','o','q','q','d','e'};
	int character[26];
	for(int i=0; i<26; i++){
		character[i] = 0;
	}
	int charLen = sizeof(c)/sizeof(c[0]);
	for(int i=0; i< charLen; i++){
		character[c[i]-97] += 1;
	}
	for(int i=0; i<26; i++){
		cout << (char)(i+97) << " " << character[i] << endl;
	}
}

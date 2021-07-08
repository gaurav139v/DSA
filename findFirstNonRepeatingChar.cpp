//https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/ O(n)
#include<bits/stdc++.h>
using namespace std;

char findResult(string s, int len){
	int end = 0, start = 0;
	map<char, int> us;
	
	while(end < len){
		us[s[end]]++;
		if(us[s[end]] > 1){
			while(us[s[start]] > 1){
				start++;
			}
		}
		end++;
	}
	if(start == len) return '-';
	return s[start];
}

int main(){
	string s = "aanhn";
	int len = s.length();
	char c = findResult(s, len);
	cout<< c << endl;
} 
	

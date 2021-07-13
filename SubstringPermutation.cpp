#include<bits/stdc++.h>
using namespace std;

void print(map<char,int> m){
	for(auto a: m)
		cout << a.first << " " << a.second << endl;
}

bool check(map<char, int> m1, map<char,int> m2, string sub){
	int len = sub.length();
	for(int i=0; i<len; i++){
		if(m1[sub[i]] != m2[sub[i]])
			return false;
	}
	return true;
}

void findResult(string s, string sub){
	
	int len1 = s.length();
	int len2 = sub.length();
	map<char, int>  m1, m2;
	int end=0,start = 0;
	
	for(int i=0; i<len2; i++){
		m1[sub[i]]++;
		m2[s[end++]]++;
	}
	
	while(end < len1){
		if(check(m1, m2, sub)){
		 cout << "Found at : " << start << endl;
		}
		m2[s[end++]]++;
		m2[s[start++]]--;				
	}
	if(check(m1, m2, sub)){
		 cout << "Found at : " << start << endl;
	}
}

int main(){
	string s = "arbcabdbbca";
	string sub = "abc";
	findResult(s, sub);
}

#include<bits/stdc++.h>
using namespace std;

bool isPermutaion(string s1, string s2){
	// using pre build data structure
	bool result;
	set<char> s;
	int count = 0;
	int len1 = s1.length();

	for(int i=0; i<len1; i++){
		s.insert(s1[i]);
	}

	for(int i=0; i<s2.length(); i++){
		if (s.find(s2[i]) != s.end()){
			count++;
		}
	}
	if (len1 == count){
		return true;
	}

	return false;
}

bool isPermutaionWithSet(string s1, string s2){
	// without pre build data structure
	int len1 = s1.length();
	int len2 = s2.length();
	int ar[26] = {0};
	
	for(int i=0; i<len1; i++){
		ar[s1[i]-97] += 1;
		ar[s2[i]-97] -= 1;
	}
	for(int i=0; i<26; i++){
		if (ar[i] != 0){
			return false;
		}
	}
	return true;
}

int main(){
	string s1 = "hello";
	string s2 = "olhel";
	int result = isPermutaion(s1, s2);
	cout << result << endl;
	result = isPermutaionWithSet(s1, s2);
	cout << result << endl;
}
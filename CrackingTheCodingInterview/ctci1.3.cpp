#include<bits/stdc++.h>
using namespace std;

string findResult(string s, int len){
	string result = "";
	for (int i=0; i<len; i++){
		if(s[i] == 32){
			result += "%20";
		}else{
			result += s[i];
		}
	}
	return result;
}

int main(){
	string result;
	string s;
	getline(cin ,s);
	int len = s.length();
	result = findResult(s,len);
	cout << result;
}

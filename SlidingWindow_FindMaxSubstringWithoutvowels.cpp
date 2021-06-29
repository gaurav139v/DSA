//https://www.geeksforgeeks.org/length-of-the-longest-substring-that-does-not-contain-any-vowel/
#include<bits/stdc++.h>
using namespace std;

int longestNonVowelSubtring(string s, int len){
	set<char> vowels {'a', 'e', 'i', 'o', 'u',
					  'A', 'E', 'I', 'O', 'U'};
	int maxLen = 0;
	int count = 0;
	
	for(int i=0; i< len; i++){
		if(vowels.find(s[i]) == vowels.end()){
			count++;
		}else{
			count = 0;
		}
		
		if(count >  maxLen){
			maxLen = count;
		}
	}
	return maxLen;
}

int main(){
	string s = "ceebbaceeffo";
	int len = s.length();
	int result = longestNonVowelSubtring(s, len);
	cout << result << endl;
}

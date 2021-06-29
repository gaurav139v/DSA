// https://www.geeksforgeeks.org/count-number-of-substrings-having-at-least-k-distinct-characters/
#include<bits/stdc++.h>
using namespace std;

int findResult(string s, int len){
	int start = 0, end=0;
	int ans = 0;
	
	unordered_map(<char> , <int>) m;
	
	while(end < len){
		m[s[end++]++;
		
		while(m.size() >= k){
			char p = s[begin];
			m[p]--;
			
			if(m[p] == 0)
				mp.erase(p);
			
			ans += len - end +1;
			begin++;
	}
	return ans;
}

int main(){
	string s = "abcca";
	int len = s.length();
	int result = findResult(s, len);
	cout << result << endl;
}

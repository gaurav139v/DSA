#include<bits/stdc++.h>
#define printTrueFalse(n) if (n) cout << "True"; else cout << "False";
using namespace std;
bool check(string first, string second,int len1,int len2){
	int i=0,j = 0;
	int flag = 0;
	if (len1 > len2){
		// insert
		while(i < len1){
			if (flag == 2) return false;
			if (first[i] == second[j]){
				i++;
				j++;
			}else{
				i++;
				flag += 1;
			}
		}
		
	}else if( len1 < len2){
		// remove
		while(i < len2){
			if (flag == 2) return false;
			if (first[i] == second[j]){
				i++;
				j++;
			}else{
				j++;
				flag += 1;
			}
		}
		
	}else{
		// replace
		while(i < len2){
			if (flag == 2) return false;
			if (first[i] == second[j]){
				i++;
				j++;
			}else{
				flag += 1;
				i++; 
				j++;
			}
		}
	}
	return true;
}
int main(){
	string first;
	string second;
	cin >> first >> second;
	int len1 = first.length();
	int len2 = second.length();
	bool result = check(first,second,len1, len2);
	printTrueFalse(result);
}

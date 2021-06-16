//find duplicate in an array of N+1 Integers O(n)
#include<bits/stdc++.h>

using namespace std;

int findDuplicate(int n[], int len){
	map<int,int> m;
	for(int i=0; i<len; i++){
		m[n[i]]++;
		if(m[n[i]] > 1)
			return n[i];
	}
	return -1;
}

int main(){
	int n[] = {6,2,3,4,1,3};
	int len = sizeof(n)/sizeof(n[0]);
	int count = findDuplicate(n, len);
	cout << count << endl;
	return 0;
}

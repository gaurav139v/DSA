//Find whether an array is a subset of another array
#include<bits/stdc++.h>

using namespace std;

int isSubString(int ar1[], int ar2[], int len1, int len2){
	map<int, int> m;
	
	for(int i=0; i<len1; i++){
		m[ar1[i]]++;
	}
	
	for(int i=0; i< len2; i++){
		if(m.find(ar2[i]) == m.end()){
			return false;
		}
	}
	return true;
		
}

int main(){
	int a1[] = {11,1,13,21,3,7};
	int a2[] = {11,3,7,1};
	int len1= sizeof(a1)/sizeof(a1[0]);
	int len2 = sizeof(a2)/sizeof(a2[0]);
	
	int result = isSubString(a1,a2,len1,len2);
	if (result)
		cout << "Yes";
	else
		cout << "No";
}

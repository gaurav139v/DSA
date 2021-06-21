// find common elements In 3 sorted arrays
#include<bits/stdc++.h>

using namespace std;

vector<int> find(int a[], int b[], int c[], int len1, int len2, int len3){
	set<int> v;
	int i=0, j=0, k=0;
	
	while(i <len1 && j< len2 && k < len3){
		if (a[i] < b[j]){
			if (a[i] < c[k]){
				i++;
			}else{
				if( c[k] < b[j]){
					k++;
				}else {
					if(a[i] == b[j] && b[j] == c[k])
						v.insert(a[i++]);
					j++;
				}}
		}else if(b[j] < c[k]){
			j++;
		}else{
			if (c[k] < a[i]){
				k++;
			}else{
				if (a[i] == b[j] && b[j] == c[k])
					v.insert(a[i]);
				i++;
			}
		}
		
		}
		
	vector<int> d(v.begin(), v.end());
	return d;
}

int main(){
	int a[] = {1,5,10,20,40,80};
	int b[] = {6,7,20,80,100};
	int c[] = {3,4,15,20,30,70,80,120};
	int len1 = sizeof(a)/sizeof(a[0]);
	int len2 = sizeof(b)/sizeof(b[0]);
	int len3 = sizeof(c)/sizeof(c[0]);
	
	
	vector<int> result = find(a, b, c, len1, len2, len3);
	for(auto x : result)
		cout << x << " ";
}

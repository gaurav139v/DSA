#include<bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
	// Code here.
	sort(v.begin(),  v.end());
	int len = v.size()/2
	;
	int result;
	
	if(v.size() % 2 == 1) result = v[len];
	else result = (v[len] + v[len-1]) / 2;
	return result;
}

int main(){
	vector<int> v {56,67,30,79};
	int result = find_median(v);
	cout << result << endl;
}

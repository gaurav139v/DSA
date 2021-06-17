//Merge Intervals O(n)
#include<bits/stdc++.h>

using namespace std;

void mergeInterval(vector<vector<int>> v, int len){
	sort(v.begin(), v.end());
	stack<vector<int>> s;
	s.push(v[0]);
	vector<int> d;
	
	for(int i=1; i<len; i++){
		if(s.top()[1] >= v[i][0]){
			int left = min(s.top()[0], v[i][0]);
            int right = max(s.top()[1], v[i][1]);
            d.push_back(left);
            d.push_back(right);
            s.pop();
            s.push(d);
            d.clear();
		}else{
			s.push(v[i]);
		}
	}
	while(!s.empty()){
		vector<int> a = s.top();
		cout << "[" << a[0] << "," << a[1] << "] ";
		s.pop();
	}
}

int main(){
	vector<vector<int>> v 
	{
		{1,4},
		{4,5}
	};
	int len = v.size();
	mergeInterval(v, len);
	return 0;
}

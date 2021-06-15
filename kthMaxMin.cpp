#include<bits/stdc++.h>

using namespace std;
struct Pair {
	int max;
	int min;
};

struct Pair getKthMaxMin(map<int,int> m, int len, int k){
	int freq = 0;
	struct Pair result;
	bool max = true, min = true;
	for(auto i= m.begin(); i != m.end(); i++){
		freq += i->second;
		if(freq >= len-k && max){
			result.max = i->first;
			max = false;
		}
		
		if(freq >= k && min){
			result.min = i->first;
			min = false;
		}
	}
	return result;
}

int main(){
	int num[] = {1,2, 5,7,83,6,7};
	int len = sizeof(num)/sizeof(num[0]);
	map<int, int> m;
	for(int i=0; i<len; i++){
		m[num[i]] += 1;
	}
	int k = 3;
	struct Pair result = getKthMaxMin(m, len, k);
	cout << result.max << " " << result.min << endl;
}

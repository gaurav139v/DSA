// Best time to buy and Sell stock O(n)
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> v, int len){
	int maxProfit = 0;
	int minPrice = 4001;
	
	for(int i=0; i<len; i++){
		if(v[i] < minPrice)
			minPrice = v[i];
		else if (v[i] - minPrice > maxProfit)
			maxProfit = v[i] -minPrice;
	}
	return maxProfit;
}

int main(){
	vector<int> v {7, 1,5,3,6,4};
	int len = v.size();
	int result = maxProfit(v, len);
	cout << result;
	return 0;
}

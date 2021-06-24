// Maximum profit by buying and selling a share atmost twice
#include<bits/stdc++.h>

using namespace std;

int findMaxProfit(int arr[], int len){
	int result[len] = {0};
			
	int maxPrice = arr[len-1];
	for(int i=len-2; i>=0; i--){
		if(arr[i] > maxPrice)
			maxPrice = arr[i];
			
		result[i] = max(maxPrice - arr[i], result[i+1]);
	}
	
	int minPrice = arr[0];
	for(int i =1; i<len; i++){
		if(arr[i] < minPrice)
			minPrice = arr[i];
		
		result[i] = max(result[i-1], (arr[i] - minPrice) + result[i]);
	}
	int profit = result[len-1];
	delete[] result;
	return profit;		
}

int main(){
	int arr[] = { 2, 30, 15, 10, 8, 25, 80 };
	int len = sizeof(arr)/sizeof(arr[0]);
	int result = findMaxProfit(arr, len);
	cout << result << endl;
}
	

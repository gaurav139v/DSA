//Kadane's Algo [V.V.V.V.V IMP] complexity O(n)
#include<bits/stdc++.h>

using namespace std;

int kadaneAlgo(int arr[], int len){
	int best = 0, sum = 0;
	for(int i=0; i<len; i++){
		sum = max(arr[i], arr[i] + sum);
		best = max(sum, best);
	}
	return best;
}

int main(){
	int arr[] = {1,2,3, -2,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	int count = kadaneAlgo(arr, len);
	cout << count << endl;
}

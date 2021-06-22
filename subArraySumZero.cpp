//Find if there is any subarray with sum equal to 0
#include<bits/stdc++.h>

using namespace std;

bool subArrayWithSumZeor(int arr[], int len){
	set<int> s;
	int sum = 0;
	
	for(int i=0; i< len; i++){
		sum += arr[i];
		
		if(s.find(sum) != s.end() || sum == 0)
			return true;
		
		s.insert(sum);
	}
	return false;	
}
int main(){
	int arr[] = {4,2,-3,1,6};
	
	int len = sizeof(arr)/sizeof(arr[0]);
	bool result = subArrayWithSumZeor(arr, len);
	if (result)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}

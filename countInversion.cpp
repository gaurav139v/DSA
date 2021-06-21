// Count Inversion O(nlogn)
#include<bits/stdc++.h>

using namespace std;

int merge(long long arr[], long long temp[], int left, int mid, int right){
	int i, j,k;
	int count=0;
	i = left;
	j = mid;
	k = left;
	while( i< mid && j <= right){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			count = count + (mid - i);
		}
	}
	
	while (i <= mid -1)
		temp[k++] = arr[i++];
	
	while (j <= right)
		temp[k++] = arr[j++];
		
	for(i= left; i<= right; i++)
		arr[i] = temp[i];
	
	return count;
}


int mergeSort(long long arr[], long long temp[], int left, int right){
	int mid, count = 0;
	if(left < right){
		mid = (right + left) / 2;
		
		count = count + mergeSort(arr,temp, left, mid);
		count = count + mergeSort(arr,temp ,mid+1,right);
		
		count = count + merge(arr, temp, left, mid +1,right);
	}
	return count;
}


int calculate(long long arr[], int len){	
	long long temp[len];
	return mergeSort(arr, temp, 0, len-1);
}
  
int main(){
	long long arr[] = {2,4,1,3,5};
	long long len = sizeof(arr)/sizeof(arr[0]);
	int result = calculate(arr, len);
	cout << result;
}

#include<iostream>

using namespace std;

struct Pair {
	int min;
	int max;
};

struct Pair getMinMax(int arr[],int len){
	struct Pair minmax;
	minmax.max = arr[0];
	minmax.min = arr[0];
	for (int i=0; i<len; i++){		
		if( arr[i] > minmax.max) minmax.max = arr[i];
		if(arr[i] < minmax.min) minmax.min = arr[i] ;
	}
	return minmax;
}

int main(){
	int num[] = {1,2,3,4,55,5,65,-4};
	int len = sizeof(num)/sizeof(num[0]);
	struct Pair result = getMinMax(num, len);	
	cout << result.max << " " << result.min << endl;
	return 0;
}

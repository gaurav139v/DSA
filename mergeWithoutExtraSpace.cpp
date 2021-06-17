// Merge 2 sorted arrays without using Extra space.
#include<bits/stdc++.h>

using namespace std;

// This solution take space O(1) and time complexity O(len1 * len2)
void mergeArray(int arr1[], int len1, int arr2[], int len2){
	
	// loop in arry arr2 from end to first
	for(int i = len2-1; i>=0; i--){
		int j, last = arr1[len1-1];
		// move in arr1 untill you find element less then arr[i]
		for(j = len1-2; j>=0 && arr1[j] > arr2[i]; j--){
			arr1[j+1] = arr1[j];
		}
		
		// if any element in arr1 moved forward
		if(j != len1-2 || last > arr2[i]){
			arr1[j+1] = arr2[i];
			arr2[i] = last;
		}
	}
}

void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void method2(int arr1[], int len1, int arr2[],int len2){
	int i=0; 
    while(arr1[len1-1]>arr2[0]){
		if (arr2[0] < arr1[i]){
			swap(&arr2[0], &arr1[i]);
	        sort(arr2, arr2 + len2);
	    }
	    i++;
	}
}

// This is the  most optimized solution agmont with space complexity O(1)..
// time complexity O((m+n)long(m+n))
void method3(int arr1[], int len1, int arr2[], int len2){
	int i=0,j=0 , k = len1 -1;
	while(i<= k && j< len2){
		if(arr1[i] > arr2[j]){
			swap(&arr2[j++], &arr1[k--]);
		}else{
			i++;
		}
	}
	sort(arr2, arr2+len2);
	sort(arr1, arr1+len1);
}

int main(){
	int arr1[] = {1, 3,5,7};
	int arr2[] = {0,2,6,8,9};
	int len1 = sizeof(arr1)/sizeof(arr1[0]);
	int len2 = sizeof(arr2)/sizeof(arr2[0]);

	//mergeArray(arr1, len1, arr2, len2);
	method3(arr1, len1, arr2, len2);
	for(auto a: arr1)
		cout << a << " ";
	cout << endl;
	for(auto a: arr2)
		cout << a << " ";
	return 0;
}

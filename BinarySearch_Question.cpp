#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int len){
	
	for(int i=0; i<len; i++){
		cout<< arr[i] << " ";
	}
	cout << endl;
}

int binarySearch(int arr[], int len, int target){
	int start = 0, end = len -1;
	while(start <= end){
		int mid = start + (end - start)/2;  // so that mid does not exceed int limit.
		if(arr[mid] == target){
			return mid;
		}else if(arr[mid] > target){
			end = mid -1;
		}else{
			start = mid + 1;
		}
	}
	return -1;
}

int binarySearch1stOccurence(int arr[], int len, int target){
	int start = 0, end = len -1;
	int result = -1;
	while(start <= end){
		int mid = start + (end - start)/2;  // so that mid does not exceed int limit.
		if(arr[mid] == target){
			result = mid;
			end = mid -1;	
		}else if(arr[mid] > target){
			end = mid -1;
		}else{
			start = mid + 1;
		}
	}
	return result;
}


int binarySearchDesc(int arr[] , int len, int target){
	int start = 0, end = len-1;
	while(start <= end){
		int mid = start + (end -start)/2;
		if(arr[mid] == target) return mid;
		else if (arr[mid] < target)
			end = mid -1;
		else
			start = mid + 1;
	}
	return -1;
}

int binarySearchCount(int arr[], int len, int target){
	int start = 0, end = len -1;
	int first = -1, last = -1;
	bool flag = true;
	
	for(int i=0; i<2; i++){
		while(start <= end){
			int mid = start + (end - start)/2;  // so that mid does not exceed int limit.
			if(arr[mid] == target){
				if(flag){
					first = mid;
					end = mid -1;	
				}else{
					last = mid;
					start = mid + 1;
				}
			}else if(arr[mid] > target){
				end = mid -1;
			}else{
				start = mid + 1;
			}
		}
		start = 0;
		end = len-1;
		flag = false;
	}
	return last - first+1;
}

int numberOfRoataion(int arr[], int len){
	int start =0, end = len -1;
	if(arr[start] < arr[end]) return -1;
	
	while(start <= end){
		int mid = start + (end - start)/2;
		int prev = (mid + len - 1)%len;
		int next = (mid + 1) % len;
		
		if(arr[prev] >= arr[mid] && arr[next] >= arr[mid])
			return mid;
		else if(arr[start] <= arr[mid])
			start = mid;
		else if(arr[mid] <= arr[end])
			end = mid;
	}

}

int searchInRoatated(int arr[],  int len, int target){
	int index = numberOfRoataion(arr, len);
	if(arr[index] == target) return index;
	
	int result = binarySearch(arr, index+1 ,target);
	if (result != -1)
		return result;
	
	result = binarySearch(&arr[index+1], len-index, target);
	if(result != -1)
		return index + result + 1;
	return -1;
	
}

int searchInNearlySorted(int arr[], int len, int target){
	int start = 0, end= len -1;
	while(start <= end){
		int mid = start + (end -start)/2;
		if(arr[mid] == target)
			return mid;
		else if(mid -1 >= start && arr[mid-1] == target)
			return mid -1;
		else if(mid + 1 <= end && arr[mid+1] == target)
			return mid+1;
	
		if(arr[mid] > target)
			end = mid - 2;
		else if(arr[mid] < target)
			start = mid + 2;
	}
	return -1;		
}

int findFloor(int arr[], int len, int target){
	int start = 0, end = len -1;
	int result = -1;
	
	while(start <= end){
		int mid = start + (end-start)/2;
		
		if(arr[mid] == target)
			return mid;
		//else if (mid -1 >= start)
			//result = mid -1;
		
		if(arr[mid] > target){
			end = mid - 1;
		}else if (arr[mid] < target){
			result = arr[mid];
			start = mid +1;
		}
	}
	return result;
}

int main(){
	int arr[] = {1,2,4,6,8,9,12,23,34,56,78}; //sorted array acs
	
	int len = sizeof(arr)/sizeof(arr[0]);
	int target = 9;
	int result = binarySearch(arr,len, target);
	cout<<"Search result at : " <<  result << endl;
	
	int arr1[] = {99,98,87,76,65,62,54,43,21,6,3,2}; // sorted array decs
	len = sizeof(arr1)/sizeof(arr1[0]);
	target = 21;
	result = binarySearchDesc(arr1,len, target);
	cout<<"Array in reverse order : " << result << endl;
	
	int arr3[] = {1,4,8,8,8,8,8,8,8,8,8,9,23,56,78}; // sorted array decs
	len = sizeof(arr3)/sizeof(arr3[0]);
	target = 8;	
	int res = binarySearch1stOccurence(arr3, len, target);
	cout <<"First occurence : "<<  res << endl; 

	
	//int arr3[] = {1,4,8,8,8,8,8,8,8,8,8,9,23,56,78}; // sorted array decs
	len = sizeof(arr3)/sizeof(arr3[0]);
	target = 8;	
	res = binarySearchCount(arr3, len, target);
	cout <<"Count : "<<  res << endl;
	
	
	int arr4[] = {400,500,55,77,88,100,133,145,200}; // sorted array decs
	len = sizeof(arr4)/sizeof(arr4[0]);
	res = numberOfRoataion(arr4, len);
	cout <<"Rotation : "<<  res << endl; 
	
	// search element in rotated array
	//r4[] = {400,500,55,77,88,100,133,145,200}; // sorted array decs
	len = sizeof(arr4)/sizeof(arr4[0]);
	target = 500 ;
	res = searchInRoatated(arr4, len, target);
	cout <<"Searched in Rotated array : "<<  res << endl; 
	
	int arr5[] = {1,2,3,5,4,6}; // sorted array decs
	len = sizeof(arr5)/sizeof(arr5[0]);
	target = 6;
	res = searchInNearlySorted(arr5, len, target);
	cout <<"Searched in Nearly sorted array : "<<  res << endl; 
	
	int arr6[] = {1,2,3,6,8,10,10,19}; // sorted array decs
	len = sizeof(arr6)/sizeof(arr6[0]);
	target = 11;
	res = findFloor(arr6, len, target);
	cout <<"Floor : "<<  res << endl; 
	
	
}

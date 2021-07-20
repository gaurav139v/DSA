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
	return 0;
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
		  
		if(arr[mid] > target){
			end = mid - 1;
		}else if (arr[mid] < target){
			result = arr[mid];
			start = mid +1;
		}
	}
	return result;
}

int findCeil(int arr[], int len, int target){
	int start = 0, end= len-1;
	int result = -1;
	
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == target){ 
			return arr[mid];
		}else if(arr[mid] > target){
			result = arr[mid];
			end = mid - 1;
		}else if(arr[mid] < target){
			start = mid + 1;
		} 
	}
	return result;
}

char findCharCeil(char arr[], int len , char target){
	int start =0, end = len -1;
	char result = '#';
	
	while(start <= end){
		int mid = start + (end -end)/2;
		if(arr[mid] == target){
			start = mid + 1; // if next char is equal to target.
		}else if(arr[mid] > target){
			result = arr[mid];
			end = mid -1;
		}else{
			start = mid + 1;
		}
	}
	return result;
}

int findInInfinteArray(int arr[], int target){
	int start = 0;
	int end = 1;
	while(target > arr[end]){
		start = end;
		end = end * 2;
	}

	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == target){
			return mid;
		}else if(arr[mid] < target){
			start = mid + 1;
		}else{
			end = mid - 1;
		}
	}
	return -1;
}

int findFirstOccur1(int arr[]){
	int target = 1, result = -1 ;
	int start = 0; 
	int end = 1;
	while(arr[end] < target){
		start = end;
		end = end * 2;
	}
	
	while(start <= end){
		int mid = start + (end - start)/2;
		
		if (arr[mid] == target){
			result = mid;
			end = mid -1;
		}else if(arr[mid] < target){
			start = mid + 1;
		}else{ 
			end = mid -1;
		}
	}
	return result;
}

int findSmallestDiff(int arr[], int len, int target){
	int start = 0, end = len-1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == target){
			return arr[mid];
		}else if(arr[mid] > target){
			end = mid -1;
		}else{
			start = mid + 1;
		}
	}
	int result = (abs(target - arr[start]) > abs(target - arr[end]))? arr[end] : arr[start];
	return result;
}

int findPeakElement(int arr[], int len){
	int start = 0, end = len -1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(mid > 0 && mid < len -1){
			if(arr[mid] > arr[mid-1] &&  arr[mid] > arr[mid+1]){
				return arr[mid];
				
			}else if(arr[mid] < arr[mid-1]){
				end = mid - 1;
				
			}else{
				start = mid + 1;
			}
		}else if(mid == 0){
			if(arr[0] > arr[1]){
				return arr[0];
			}else {
				return arr[1];
			}
		}else if(mid == len -1 ){
			if(arr[len -1] >  arr[len -2]){
				return arr[len-1];
			}else {
				return arr[len -2];
			}
		}
	}
	return -1;
}

int findMaxInBitonic(int arr[], int len){
	int start = 0, end = len -1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(mid >0 && mid < len -1){
			if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
				return mid;
			}else if(arr[mid] < arr[mid-1]){
				end = mid -1;
			}else {
				start = mid + 1;
			}
		}else if(mid == 0){
			if(arr[mid] >  arr[mid+1]){
				return mid;
			}else{
				return mid+1;
			}
		}else if(mid == len -1){
			if(arr[mid] > arr[len -2]){
				return mid;
			}else { 
				return len-2;
			}
		}
	}
	return -1;
}

int findInBitonic(int arr[], int len, int target){
	int peak = findMaxInBitonic(arr, len);
	
	int result = binarySearchDesc(&arr[peak], len - peak , target);
	if(result != -1)
		return result + peak;
	return binarySearch(arr, peak+1, target);
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
	
	res = findCeil(arr6, len, target);
	cout <<"Ceil : "<<  res << endl;
	
	char arr7[] = {'a','b', 'c','g', 'f', 'i', 'm'};
	len = sizeof(arr7)/sizeof(arr7[0]);
	char tar = 'c';
	char r = findCharCeil(arr7, len, tar);
	cout << "Ceil of char : " << r << endl;
	
	int arr9[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1}; // sorted array decs
	len = sizeof(arr9)/sizeof(arr9[0]);
	target = 23;
	res = findFirstOccur1(arr9);
	cout <<"First occurence of 1 in Infinity array : "<<  res << endl; 
	
	//find the smallest differene in infinite array
	int arr10[] = {1,2,3,6,8,11,13,19}; // sorted array decs
	len = sizeof(arr10)/sizeof(arr10[0]);
	target = 9;
	res = findSmallestDiff(arr10, len, target);
	cout <<"Smallest difference in infinite array : "<<  res << endl; 
			
	// peak element in unsorted array
	// element is peak if its left and right element are smaller
	int arr11[] = {1,2,3,24,6,14,13,12}; // sorted array decs
	//int arr11[] = {99,98,87,76,65,62,54,43,21,6,3,2};
	len = sizeof(arr11)/sizeof(arr11[0]);
	target = 9;
	res = findPeakElement(arr11, len);
	cout <<"Find the peak element in unsorted array : "<<  res << endl; 
	
	
	int arr12[] = {1,2,4,5,7,14,16,15,12,11,3};
	//int arr12[] = {5,4};
	len = sizeof(arr12)/sizeof(arr12[0]);
	target = 9;
	res = findMaxInBitonic(arr12, len);
	cout <<"Maximum element in bitonic array : "<<  arr12[res] << endl; 
	
	// search element in bitonic array.
	//int arr12[] = {1,2,4,5,7,14,16,15,12,11,5,3};
	//int arr12[] = {5,4};
	len = sizeof(arr12)/sizeof(arr12[0]);
	target = 7;
	res = findInBitonic(arr12, len, target);
	cout<< res << endl;
	cout <<"Searchin bitonic array : "<<  res << endl; 
	
	
}

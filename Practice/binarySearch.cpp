#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int start=0;
    int end=n-1;

    while(start < end){
        int mid = (start + end)/2;

        if (arr[mid] > key){
            end = mid - 1;
        }else if (arr[mid] < key){
            start = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
   int arr[] = {3,5,7,34,56,78,98,123,456};
   int n = sizeof(arr)/sizeof(int);
   int key;
   cin >> key;
   cout << binarySearch(arr, n, key) << endl;
   return 0;   
}
// Selection sort
#include<bits/stdc++.h>
using namespace std;

void swap(int *first, int *second){
    int temp = *first;
    *second = *first;
    *first = temp;
}

void print(int arr[], int n){
    for(int i=0; i< n; i++){
        cout << arr[i] << " ";
    }
}

int selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min_int = INT_MAX;

        for(int j=i; j<n; j++){
            if(arr[j] < arr[min_int]){
                min_int = j;
            }        
        }

        swap(arr[min_int], arr[i]);
    }

    return 0;
}

int main(){
   int arr[] = {3,748,948,1243,45, 6, 76};
   int n = sizeof(arr)/sizeof(int);
   selectionSort(arr, n);
   print(arr, n);
   return 0;   
}
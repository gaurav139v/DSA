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


int main(){
   int arr[] = {3,748,948,1243,45, 6, 76};
   int n = sizeof(arr)/sizeof(int);
   
   return 0;   
}
// Amazon question
#include<bits/stdc++.h>
// #include<iostream>
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

int maxOfAllMin(int arr[], int n, int segmentLenght){
   int left = 0;
   int right = segmentLenght -1;
   vector<int> data; 
   while(right < n){
       int min_i = INT_MAX;
       for(int i=left; i<= right; i++){
           if(min_i > arr[i]){
               min_i = arr[i];
           }
       }
       data.push_back(min_i);
       left++;
       right++;
   }

   int mx = INT_MIN;
   for(auto a: data){2299 1278 8505    
       if(mx < a){
           mx = a;
       }
   }
   return mx;
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
   
   int arr[] = {8,2,4};
   int n = sizeof(arr)/sizeof(int);
   int rem = 2;
   // output should be 2

   int result  = maxOfAllMin(arr, n, rem);
   cout << result << endl;
   
   return 0;   
}
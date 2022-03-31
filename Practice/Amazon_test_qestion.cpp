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

int remove(int arr[], int n, int rem){
    int result;
    map<int , int> data;
    for(int i=0; i<n; i++){
        data[arr[i]]++;
    }
    
    vector<int> res;
    for(auto i: data){
        res.push_back(i.second);
    }
    sort(res.begin(), res.end());
    result = res.size();
        
    for(auto i : res){
        if (rem <= 0) break;
        if(i < rem){
            rem -= i;
            result--;
            continue;
        }
    }

    return result;
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
   
   int arr[] = {1,1,1,1,2,3,2,2,3,3};
   int n = sizeof(arr)/sizeof(int);
   int rem = 2;
   // output should be 2

   int result  = remove(arr, n, rem);
   cout << result << endl;
   
   return 0;   
}
// Find longest coinsecutive subsequence
#include<bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int dp[5001]={-2};
      int count = 0;
      int best = 0;
      
      for(int i=0; i<N; i++){
          dp[arr[i]] = arr[i];
      }
     
      
      for(int i=0; i< 5001; i++){
            if(dp[i+1] - dp[i] == 1)
                count++;
                
            else
                count = 0;
            
            if(count > best)
                best = count;
      }
      return best+1;
      
}

int main(){
	int arr[] = {61,130};// {9 ,8 ,7 ,6, 5, 4, 9, 8, 7, 6, 5, 4, 4};
	int len = sizeof(arr)/sizeof(arr[0]);
	int result = findLongestConseqSubseq(arr, len);
	cout << result << endl;
}

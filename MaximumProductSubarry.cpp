// find maximum product subarray  O(n)
#include<bits/stdc++.h>

using namespace std;

long long findMaxProd(long long a[], int n){
	    long long ma = a[0];
	    long long mi = a[0];
	    long long best = a[0];
	    
	    for(int i=1; i<n; i++){
	        if(a[i] < 0)
	            swap(mi, ma); // because -ve * -ve become Max
	        
	        mi = min<long long>(a[i], a[i] * mi);
	        ma = max<long long>(a[i], a[i] * ma);
	        
	        if(ma > best)
	            best = ma;
	    }
	    return best;
}

int main(){
	long long a[] =  {6, -3, -10, 0, 2};
	int len = sizeof(a)/sizeof(a[0]);
	int result = findMaxProd(a, len);
	cout << result << endl;
}

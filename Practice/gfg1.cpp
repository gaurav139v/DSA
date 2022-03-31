// { Driver Code Starts
// Initial Template for C

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C


int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    // code here
    set<int> s;
    
    for(int i=0; i<n; i++){
        s.insert(a[i]);
    }
    
    int count = 0;
    for(int i=0; i< m; i++){
        if(s.find(b[i]) != s.end()){
            count++;
        }
    }
    return count;
    
}


// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        int *a;
        a = (int *)malloc(n * sizeof(int));

        int *b;
        b = (int *)malloc(m * sizeof(int));

        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        for (int i = 0; i < m; i++) scanf("%d", &b[i]);

        printf("%d\n", NumberofElementsInIntersection(a, b, n, m));
    }
    return 0;
}  // } Driver Code Ends
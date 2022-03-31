#include<bits/stdc++.h>


using namespace std;

int main(){
    int t;
    cin >> t;
    int n;


    while(t--){
        cin >> n;
        int result = pow(2, n)-1;
        cout << result << endl;
    }
    return 0;
}
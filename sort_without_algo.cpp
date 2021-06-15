#include<iostream>

using namespace std;

void sort(int n[], int len){
	int val[3] = {0};
	for(int i=0; i<len; i++){
		val[n[i]] += 1;
	}
	
	int k = 0;
	for(int i=0; i<3; i++){
		for(int j=0; j<val[i]; j++){
			n[k++] = i;
		}
	}
}
	
int main(){
	int n[] = {1, 0,0,0,1,1,2,0,2,1,0};
	int len = sizeof(n)/sizeof(n[0]);
	sort(n, len);
	for(auto a: n)
		cout << a << " ";

}

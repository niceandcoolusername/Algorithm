#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cutrod(int price[],int n){
	int val[n+1];
	val[0]=0;
	int i,j;
	for(i=1;i<=n;i++){
		int maxi=INT_MIN;
		for(j=0;j<i;j++){
			maxi=max(maxi,price[j]+val[i-j-1]);
			
		}
	val[i]=maxi;
	}
	return val[n];

}
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
  	cout<<cutrod(arr,size)<<endl;
    return 0;
}
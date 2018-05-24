#include<bits/stdc++.h>
using namespace std;

int max_elements(int arr[],int n){
	int max_diff=arr[1]-arr[0];
	int min_element=arr[0];

	for(int i=1;i<n;i++){
		if(arr[i]-min_element>max_diff)
			mx_diff=arr[i]-min_element;
		if(arr[i]<min_element)
			min_element=arr[i];
	}
	return max_diff;
}

int main(){
	int arr[]={1,2,90,10,110};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<"max diff"<<max_elements(arr,n)<<endl;
}
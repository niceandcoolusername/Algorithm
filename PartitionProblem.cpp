#include<iostream>
using namespace std;

bool partition(int arr[],int n){
	int sum;
	for(int i=0;i<n;i++){
		sum+=arr[i];

	}
	if(sum%2==0)
		return false;
	bool part[sum/2 +1][n];
	for(int i=0;i<=n;i++){
		part[0][i]=true;
	}
	for(int j=0;j<=sum/2;j++){
		part[j][0]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum/2;j++){
			part[j][i]=part[j][i-1];
			if(i>=arr[j-1])
				part[j][i]=part[j][i] || part[j-arr[i-1]][i-1]
		}
	}
}
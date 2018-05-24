#include<bits/stdc++.h>
using namespace std;

int maxcoins(vector<int>nums1){
	int n=nums1.size();
	 int nums[] = new int[nums1.size() + 2];
        nums[0] = 1;
        nums[nums.length-1] = 1;
        for (int i = 0; i < nums1.length; i++) {
            nums[i+1] = nums1[i];
        }
	int T[n+2][n+2];
	memset(T,0,sizeof(T));
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j>=1;j--){
			for(int k=j;k<=i;k++)
				T[j][i]=max(nums[j-1]*nums[k]*nums[i+1]+T[j][k-1]+T[k+1][i],dp[j][i]);
		}
	}


	return T[1][n-2];
}

int main(){

	vector<int> arr;
	
	for(int i=0;i<=arr.size();i++){
		cin>>arr[i];
	}

	
	maxcoins(arr);


	return 0;
}
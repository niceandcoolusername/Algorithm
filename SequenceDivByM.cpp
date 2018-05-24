#include<bits/stdc++.h>
using namespace std;

const int MAX=1000;

bool isdivisible (int arr[],int M,int n,int dp[][MAX],int index,int sum){
	if(index==n)
	{
		if(sum%M==0)
			return true;
		else
			return false;

	}


	if(dp[index][sum]!=-1)
		return true;
	bool ispositive=isdivisible(arr,M,n,dp,index+1,sum+arr[index]);
	bool isnegativr=isdivisible(arr,M,n,dp,index+1,sum-arr[index]);
	bool res=(ispositive||isnegativr);

	dp[index][sum]=res;

	return res;
}

int main(){
	int arr[] = { 1, 2, 3, 4, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int M = 4;
 
    int dp[n + 1][MAX];
    memset(dp, -1, sizeof(dp));
 
    bool res;
    res = isdivisible(arr,M,n,dp,0,0);
 
    cout << (res ? "True" : "False") << endl;
    return 0;
}
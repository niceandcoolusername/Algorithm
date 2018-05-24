#include<iostream>
using namespace std;

int work(int high[],int low[],int n){
	int dp[n+1];
	dp[0]=0;
	dp[1]=high[0];

	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i-2]+high[i-1],dp[i-1]+low[i-1]);
	}
	return dp[n];
}

int main(){
	int n=5;
	int high[] = {3, 6, 8, 7, 6};
    int low[] = {1, 5, 4, 5, 3};

    cout<<work(high,low,n);
    return 0;
}
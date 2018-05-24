#include<bits/stdc++.h>
using namespace std;

int count(int dp[][2][3],int n,int bcount=1,int ccount=2){
	if(bount<0 || ccount<0)
		return 0;
	if(n==0)
		return 1;
	if(bcount==0 && ccount ==0)
		return 1;

	if(dp[n][bcount][ccount]!=-1){
		return dp[n][bcount][ccount];
	}
	int res=count(dp,n-1,bcount,ccount)+count(dp,n-1,bcount-1,ccount)+count(dp,n-1,bcount,ccount-1);
	return (dp[n][bcount][ccount]=res);}

	int countu(int n){
		int dp[n][bcount][ccount];
		memset(dp,-1,sizeof(dp));

		return count(dp,n);
	}

	int main(){
		int n = 3; // Total number of characters
    cout << count(n);
    return 0;
	}
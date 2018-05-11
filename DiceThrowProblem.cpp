#include<bits/stdc++.h>
using namespace std;

int dicethrow(int n,int m,int x){
	int dp[n+1][x+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m && i<=x;i++){
		dp[1][i]=1;
	}

	for(int i=2;i<=n;i++){
		for(int j=1;j<=x;j++){
			for(int k=1;k<=m && k<j;k++){
				dp[i][j]+=dp[i-1][j-k];    //this step is like in previous step if we get k so now we have 1 less dice and sum-k!
			}
		}
	}
	return dp[n][x];
}

int main()
{
    cout << dicethrow(4, 2, 1) << endl;
    cout << dicethrow(2, 2, 3) << endl;
    cout << dicethrow(6, 3, 8) << endl;
    cout << dicethrow(4, 2, 5) << endl;
    cout << dicethrow(4, 3, 5) << endl;
 
    return 0;
}
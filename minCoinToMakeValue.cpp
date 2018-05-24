#include<bits/stdc++.h>
using namespace std;

int minCoin(int coin[],int V,int n){

	int dp[V+1];
	dp[0]=0;
	for(int i=1;i<=V;i++)
		dp[i]=INT_MAX;
	for(int i=1;i<=V;i++)
	{
		for(int j=0;j<n;j++)
			if(coin[j]<=i){
				int sub_res=dp[i-coin[j]];
				if(sub_res!=INT_MAX && sub_res+1<dp[i])
					dp[i]=sub_res+1;
			}
	}
	return dp[V];

}

int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoin(coins,V,m);
    return 0;
}
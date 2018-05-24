#include<iostream>
using namespace std;
int dp[MAX][MAX][MAX][3];

int countball(int p,int q,int r,int last){
	if(p<0 || q<0 || r<0)
		return 0;

	if(p==1 && q==0 && r==0 && last=0)
		return 1;
	if(r==1 && p==0 && r==0 && last=2)
		return 1;
	if(q==1 && p==0 && r==0 && last=1)
		return 1;

	if(dp[p][q][r][last]!=-1)
		return dp[p][q][r][last];
	if(last==0)
		dp[p][q][r][0]=countball(p-1,q,r,1)+countball(p-1,q,r,2);
	 else if (last==1)
       dp[p][q][r][last] = countWays(p,q-1,r,0) + countWays(p,q-1,r,2);
    else 
       dp[p][q][r][last] =  countWays(p,q,r-1,0) + countWays(p,q,r-1,1);
 
    return dp[p][q][r][last];
}

int countfinal(int p,int q,int r){
	memset(dp,-1,sizeof(dp));

	return countball(p,q,r,0)+countball(p,q,r,1)+countball(p,q,r,2);
}

int main(){
	int p=1,q=1,r=1;
	cout<<countfinal(p,q,r);
	return 0;
}
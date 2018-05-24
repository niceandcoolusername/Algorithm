#include<iostream>
using namespace std;

const int MAX=1000;

int dp[MAX][MAX][MAX][2];

int countUtil(int i,int j,int k,int d){
	if(i<0 || j<0)
		return 0;
	if(i==0 && j==0 )
		return 1;
	if(k==0){
		if(d==0 && i==0)  //if k==0 then they can either move horizontally or vertically but no turning allowed!
			return 1;
		if(d==1 && j==0)
			return 1;
		return 0;
	}

	if(dp[i][j][k][d]!=-1)     //check for memoized values(memoization)
		return dp[i][j][k][d];
	if(dp==0)
		return dp[i][j][k][d]=countUtil(i,j-1,k,d)+countUtil(i-1,j,k,!d);
	return dp[i][j][k][d]=countUtil(i-1,j,k,d)+countUtil(i,j-1,k,!d);
}
 
 int countpath(int i,int j,int k)
 {
 	if(i==0 && j==0)
 		return 1;
 	memset(dp,-1,sizeof dp);
 	return countUtil(i-1,j,k,1)+countUtil(i,j-1,k,0);


 }

 int main()
{
    int m = 3, n = 3, k = 2;
    cout << "Number of paths is "
         << countpath(m-1, n-1, k) << endl;
    return 0;
}
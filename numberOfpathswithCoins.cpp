#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3
#define MAX_K 1000

int dp[R][C][MAX_K];

int pathcount(int mat[][C],int m,int n,int k){
	if(m==0 and n==0)
	    return k==mat[0][0];
	if(dp[m][n][k]!=-1)
		return dp[m][n][k];
	dp[m][n][k]=pathcount(mat,m-1,n,k-mat[m][n])+pathcount(mat,m,n-1,k-mat[m][n]);
	return dp[m][n][k];
}

int pathcountfinal(int mat[][C],int k){
	memset(dp,-1,sizeof(dp));
	return pathcount(mat,R-1,C-1,k);
}

int main(){
	int k=12;
	int mat[R][C] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
                  };
    cout << pathcountfinal(mat, k);
    return 0;
}
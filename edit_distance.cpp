#include<iostream>
#include<string>
using namespace std;

int min(int x,int y,int z){
 return min(min(x,y),z);
}

int editDist(string x,string y,int n,int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0){
				dp[i][j]=j;
			}
			else if(j==0){
				dp[i][j]=i;

			}

			else if(x[i-1]==y[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}

			else{
				dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
			}
		
		}

	}
return dp[n][m];
}

int main()
{
    
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDist(str1, str2, str1.length(), str2.length())<<endl;;
 
    return 0;
}
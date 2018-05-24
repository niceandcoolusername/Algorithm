#include<bits/stdc++.h>
#define MAX_CHAR 1000
using namespace std;

int cds(string str){
	int n=str.length();

	int dp[n+1];
	dp[0]=1;
	vector<int> last(MAX_CHAR,-1);
	for(int i=1;i<=n;i++){
		dp[i]=2*dp[i-1];
		if(last[str[i-1]]!=-1)
			dp[i]=dp[i]-dp[last[str[i-1]]];
		last[str[i-1]]=i-1;
	}
	return dp[n];
}

int main(){
	cout<<cds("gfg");
	return 0;
}

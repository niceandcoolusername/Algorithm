#include<iostream>
using namespace std;

int egg(int n,int k1){
	int k[n+1][k1+1];
	int res;
	int i,j,x;

	for(i=1;i<=n;i++){
		k[i][1]=1;
		k[i][0]=1;
	}
	for (j=1;j<=k1;j++){
		k[1][j]=j;

	}

	for(i=2;i<=n;i++){
		for(j=2;j<=k1;j++){
			k[i][j]=100000;
			for(x=1;x<=j;x++){
				res=1+max(k[i-1][x-1],k[i][j-x]);
				if(res<k[i][j]){
					k[i][j]=res;
				}
			}
		}
	}
	return k[n][k1];
}

int main()
{
    int n = 2, k = 36;
    cout<<egg(n,k)<<endl;
return 0;}
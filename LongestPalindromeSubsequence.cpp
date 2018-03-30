#include<iostream>
#include<string>
#include <sstream>
using namespace std;

int pal(char a[],int n){
	
	int k[n][n];
	for(int i=0;i<=n;i++){
		k[i][i]=1;
	}
	for(int L=2;L<=n;L++){
		for(int i=0;i<n-L+1;i++){
			int j=i+L-1;
			if(a[i]==a[j] && L==2){ //Have to include case when 
				k[i][j]=2;
			}
			else if(a[i]==a[j]){
				k[i][j]=2+k[i+1][j-1];
			}
			else{
				k[i][j]=max(k[i][j-1],k[i+1][j]);
			}
		}
	}
return k[0][n-1];
}

int main()
{
    char seq[]= "GEEKS FOR GEEKS";
    
   cout<<pal(seq,15)<<endl;
    return 0;
}
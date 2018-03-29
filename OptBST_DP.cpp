#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int add(int freq[],int i,int j){
	int s=0;
	for(int k1=i;k1<=j;k1++){
		s=s+freq[k1];
	}
	return s;
}

int opt(int keys [],int freq[],int n){

int cost[n][n];
for(int i=0;i<n;i++){
	cost[i][i]=freq[i];           //WE ASSUME SORTED KEYS FUNCTION,IF NOT THEN SORT KEYS AND FREQUENCY ACCORDINGLY!
//L=1 INCLUDED HERE!
}
for(int L=2;L<=n;L++){ //FOR REST OF L WE HAVE TO DO
	for(int i=0;i<n-L+1;i++){ //i<n-l+1 BECAUSE VISUALISE THE TABLE ITS ONLY TRIANGULAR TABLE AND HENCE COULD BE VISUALISED
		int j=i+L-1;
		cost[i][j]=INT_MAX;
		for(int r=i;r<=j;r++) {
			int c=((r>i)? cost[i][r-1]:0)+((j>r)?cost[r+1][j]:0)+add(freq,i,j);
			if(c<cost[i][j]) cost[i][j]=c; //IF COST IS LOWER THEN ONLY WE INCLUDE IT ,BECAUSE COST IS TO BE MINIMIZED,THUS INITIALLY ASSIGNED int_min TO COST!

		}
	}
}
return cost[0][n-1]; //MAX VALUE OBTAINED IN FIRST ROW AND LAST COLUMN,INDEX SATRTS AT 0 AND HENCE ENDS AT n-1
}

int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<opt(keys,freq,n)<<endl;
    return 0;
}
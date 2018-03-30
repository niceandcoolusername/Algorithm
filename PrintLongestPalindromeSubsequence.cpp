#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string lcs(string &x,string &y){
	int m=x.length();
   	int n=y.length();
	int l[m+1][n+1];

	for(int i=0;i<=m;i++){                 //WE ARE WRITING FUNCTION FOR LCS AND THEN WILL FIND Lcs OF A STRING AND REVERSE OF THAT STRING!!
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				l[i][j]=0;
			}
			else if(x[i-1]==y[j-1]){
				l[i][j]=1+l[i-1][j-1];
			}
			else{
				l[i][j]=max(l[i-1][j],l[i][j-1]);
			}
		}
	}

	int index=l[m][n];
	string lc(index+1,'\0');
	int i=m;
	int j=n;
	while(i>0 && j>0){
	if(x[i-1]==y[j-1]){
		lc[index-1]=x[i-1];
		i--;
		j--;
		index--;
	}
	else if(l[i-1][j]>l[i][j-1]){
		i--;
	}
	else{
		j--;
	}}
return lc;
}

string longestpalindrome(string &x){
	string rev=x;                        //FUNCTION TO CALCULATE LCS OF STRING BOTH REVERSE AND STAIGHT !
	reverse(rev.begin(),rev.end());
	return lcs(x,rev);}

int main()
{
    string str = "GEEKSFORGEEKS";
    cout <<longestpalindrome(str)<<endl;
    return 0;
}
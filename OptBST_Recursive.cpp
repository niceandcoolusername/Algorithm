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

int opt(int freq[],int i,int j){
	if(j<i) return 0;
	if(j==i) return freq[j];
	int sum=add(freq,i,j);
	int min=INT_MAX;

	for(int r=i;r<=j;r++){
		int cost=opt(freq,i,r-1)+opt(freq,r+1,j);
		if (cost<min){min=cost;}
}
return min+sum;
	}

	int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<opt(freq,0,n-1);

}
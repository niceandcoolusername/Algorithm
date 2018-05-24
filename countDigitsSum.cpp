#include<iostream>
using namespace std;
unsigned long long lookup[101][501];
unsigned long long int count(int n,int sum){
	 

	 if(n==0)
	 	return sum==0;

	 if(lookup[n][sum]!=-1)
	 	return lookup[n][sum];

	 unsigned long long int ans=0;

	 for (int i=0;i<10;i++)
	 	if(sum-i>=0)
	 		ans+=count(n-1,sum-i);

	 return lookup[n][sum]=ans;




}

unsigned long long countfinal(int n,int sum){
	memset(lookup,-1,sizeof(lookup));
	unsigned long long ans=0;

	for(int i=1;i<=9;i++)
		if(sum-i>0)
			ans+=countfinal(n-1,sum-i);

	return ans;
}

int main(){
	int n = 3, sum = 5;
    cout << countfinal(n, sum);
    return 0;
}
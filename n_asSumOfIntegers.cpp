#include<iostream>
using namespace std;

int count_ways(int n){
	int count[n+1];
	memset(count,0,sizeof(table));
	count[0]=1;

	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			count[j]+=count[j-i];
		}
	}
	return count[n];
}

int main(){
	int n=7;
	cout<<count_ways(n)<<endl;
	return 0;
}
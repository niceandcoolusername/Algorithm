#include<iostream>
using namespace std;
int maxi(int a,int b,int c){
    return(max(max(a,b),c));
}

int maxp(int n){
	int val[n+1];
	val[0]=0;
	val[1]=0;

	for(int i=1;i<=n;i++){
		int maxv=0;
		for(int j=1;j<=i/2;j++){
			maxv=maxi(maxv,(i-j)*j,j*val[i-j]);
	
	}
	val[i]=maxv;
	}
	return val[n];
}

int main(){
	cout<<maxp(10)<<endl;
}
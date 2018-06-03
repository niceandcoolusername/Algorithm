#include<iostream>
using namespace std;

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int pour(int fromCap,int toCap,int d){
	int from=fromCap;
	int to=0;

	int steps=1;
	while(from !=d && to!=d){
		int temp=min(from,toCap-to);

		to+=temp;
		from-=temp;
		steps++;
		if(from==d || to==d)
			break;

		if(from==0){
			from=fromCap;
			steps++;
		}
		if(to==toCap){
			to=0;
			steps++;
		}
	}
	return steps;
}

int minsteps(int m,int n,int d){
	if(m>n){
		swap(m,n);
	}
	if(d>n)
		return -1;
	if((d%gcd(n,m))!=0)
		return -1;
	return min(pour(n,m,d),pour(m,n,d));
}

int main(){
	int n = 3, m = 5, d = 4;
 
    cout<<minsteps(m,n,d)<<endl;
 
    return 0;
}
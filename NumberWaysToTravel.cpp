#include<iostream>
using namespace std;

int printcount(int distance){
	int count[distance+1];
count[0]=1;
count[1]=1;
count[2]=2;

for(int i=3;i<=distance;i++)
{
	count[i]=count[i-1]+count[i-2]+count[i-3];
}
return count[distance];
}

int main(){
	int dist=4;
	cout<<printcount(dist);

	return 0;
}
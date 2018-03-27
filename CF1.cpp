#include<iostream>
#include<stdio.h>

#include<string>
using namespace std;

int main(){
	int t1,t2,t3,t4;
	int name[100000];
	cin>>t1>>t2>>t3>>t4;
	fgets(name);
	int s=0;
	while(sizeof(name))
	{
		int i;
		if(name[i]==1){
			
			s=s+(t1*name[i]);
			i++;
		}
		if(name[i]==2){
			
			s=s+(t2*name[i]);
			i++;
		}
		if(name[i]==3){
			
			s=s+(t3*name[i]);
			i++;
		}
		if(name[i]==4){
			
			s=s+(t4*name[i]);
			i++;
		}
	}
cout<<s;
return 0;
}
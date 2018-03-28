#include<iostream>
using namespace std;

void activity(int n,int s[],int f[]){
	int i,j;
	i=0;
	for(j=0;j<n;j++){
		if(f[i]<=s[j]){
			cout<<j<<endl;
			i=j;
		}
	}
}

int main(){
	int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    activity(n,s,f);
    return 0;
}
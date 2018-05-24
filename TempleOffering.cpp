#include<iostream>
using namespace std;

struct temple{
	int L,R;
};
int max1(int a,int b){
	if(a>=b)
	    return a;
	else
	    return b;
}
int offerings(int n,int templeHeight[]){
	temple chainsize[n];
	for(int i=0;i<n;i++){
		chainsize[i].R=-1;
		chainsize[i].L=-1;
	}

	chainsize[0].L=1;
	chainsize[n-1].R=1;

	for(int i=1;i<n;i++){
		if(templeHeight[i-1]<templeHeight[i])
			chainsize[i].L=chainsize[i-1].L+1;
		else
			chainsize[i].L=1;
	}

	for(int i=n-1;i>=0;i--){
		if(templeHeight[i+1]<templeHeight[i])
			chainsize[i].R=chainsize[i+1].R+1;
		else 
			chainsize[i].R=1;

	}

	int max=0;
	int sum=0;

	for(int i=0;i<n;i++){
		sum+=max1(chainsize[i].L,chainsize[i].R);
	}

	return sum;
}


int main(){
	int arr1[3] = {1, 2, 2};
    cout << offerings(3, arr1) << "\n";
    int arr2[6] = {1, 4, 3, 6, 2, 1};
    cout << offerings(6, arr2) << "\n";
    return 0;
}
#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int knapsack(int val[],int weight[],int W,int n){

int k[n+1][W+1];

for(int i=0;i<=n;i++){
	for(int w=0;w<=W;w++){
		if(i==0||w==0){
			k[i][w]=0;
		}
		else if(weight[i-1]<=w){k[i][w]=max(val[i-1]+k[i-1][w-weight[i-1]],k[i-1][w]);

		}
	else{
		k[i][w]=k[i-1][w];
	}
	}
}

return k[n][W];
}

int main(){

    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    cout<<knapsack(val,wt,W,3)<<endl;
    return 0;

}
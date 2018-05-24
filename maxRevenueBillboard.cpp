#include<bits/stdc++.h>
using namespace std;

int maxrevenue(int m,int x[],int revenue[],int n,int t){
	int maxrev[m+1];
	 memset(maxrev,0,sizeof(maxrev));
	 int nxtbb=0;
	 for(int i=0;i<=m;i++){

	 	if(nxtbb<n){
	 		if (x[nxtbb]!=i)
	 		{
	 			maxrev[i]=maxrev[i-1];
	 		}
	 		else{
	 			if(i<t)
	 				maxrev[i]=max(maxrev[i-1],revenue[nxtbb]);
	 			else
	 				maxrev[i]=max(maxrev[i-t-1]+revenue[nxtbb],maxrev[i-1]);
	 			nxtbb++;
	 		}
	 	}
	 	else{
	 		maxrev[i]=maxrev[i-1];
	 	}



	 }

return maxrev[m];
}

int main(){
	int m = 20;
    int x[] = {6, 7, 12, 13, 14};
    int revenue[] = {5, 6, 5, 3, 1};
    int n = sizeof(x)/sizeof(x[0]);
    int t = 5;
    cout << maxrevenue(m, x, revenue, n, t) << endl;
    return 0;
}
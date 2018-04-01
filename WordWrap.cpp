#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int print(int p[],int n){
	int k;
	if(p[n]==1)
		k=1;
	else
		k=print(p,p[n]-1)+1;
	cout<<"Line number "<<k <<"From word no" <<p[n]<<"to" <<n<<endl;
	return k;
}

void wordwrap(int l[],int n, int M){
	int extras[n+1][n+1];
	int lc[n+1][n+1];
	 for (int i=1;i<=n;i++){                        //THIS PART TELLS US HOW TO CACLUATE THE EXTRA APACES
	 	extras[i][i]=M-l[i-1];
	 	for(int j=i+1;j<=n;j++){
	 		extras[i][j]=extras[i][j-1]-1-l[j-1]; //EXTRAS TILL j-1 AND THEN WE INCLUDE THE jth WORD BUT THAT CAN BE ACCESSED BY l[j-1] AND -1 IS FOR THE SPACE BETWEEN WORDS 
	 	}
	 }

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){
			if(extras[i][j]<0){lc[i][j]=INF;}
		
		else if(extras[i][j]>=0 && j==n){              //THIS PART TELLS US ABOUT THE COST STARTING FROM A NUMBER ENDING TO ANOTHER
			lc[i][j]=0; //IF j=n THIS MEANS THAT THE WHOLE SENTENCE IS IN THE FIRST LINE AND HENCE THEY HAVE MINIMUM COST,CAUSE WE DONT NEED TEXT JUSTIFICATION 
		}
		else{
			lc[i][j]=extras[i][j]*extras[i][j];
		}}
	}

	int c[n+1];
	int p[n+1];
	c[0]=0;
	for(int j=1;j<=n;j++){
		c[j]=INF;
		for(int i=1;i<=j;i++){                  //THIS PART TELLS US THE COST STARTING FROM 1 TO J RESPECTIVELY
			
			if(c[i-1] !=INF && lc[i][j]!=INF && (c[i-1]+lc[i][j]<c[j])){
				c[j]=c[i-1]+lc[i][j]; //TOTAL COST IS EQUAL TO COST TILL i-1 AND THE COST FROM i TO j(i-1 IS ALREADY INCLUDED)
				p[j]=i;
			}
		}
	}
	print(p,n);
}

int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
     wordwrap(l, n, M);
    return 0;
}
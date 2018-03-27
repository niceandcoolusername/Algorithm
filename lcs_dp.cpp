#include<iostream>
#include<string>
using namespace std;
int max(int a, int b)
{
    return (a > b)? a : b;
}
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   
}

int index=L[m][n];
char lcs[index+1];
lcs[index]='\0';
int i1=m;
int j1=n;
while(i1>0 && j1>0){
	if(X[i1-1]==Y[j1-1]){
		lcs[index-1]=X[i1-1];
		i1--;
		j1--;
		index--;
	}
	else if(L[i1-1][j1]>L[i1][j1-1]){i1--;

	}
else
	j1--;
}

cout<<lcs<<"is lcs"<<endl;

}
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  
  int m = 6;
  int n = 7;
  
 lcs(X,Y,m,n);
  return 0;
}
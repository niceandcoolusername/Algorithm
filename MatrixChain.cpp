#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printParenthesis(int i,int j,int n,int *bracket,char &name){
	if(i==j){
		cout<<name++;
		return;}
	cout<<"(";
	
	printParenthesis(i,*(bracket+i*n+j),n,bracket,name);
	
	printParenthesis(*(bracket+i*n+j)+1,j,n,bracket,name);
	cout<<")";
	
	
	

}

int matrixchain(int p[],int n){
	int m[n][n];
	int brackets[n][n];
int i,L,k,j,q;
	for(i=1;i<n;i++){
		m[i][i]=0;
	}
	for(L=2;L<n;L++){
		for(i=1;i<n-L+1;i++){
			j=i+L-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++){q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]) {m[i][j]=q;
					       brackets[i][j]=k;
					      
					      }

			}
		}
	}
	
    char name = 'A';
 
    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n-1, n, (int *)brackets, name);
    cout << "nOptimal Cost is : " << m[1][n-1];


}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
   cout<<matrixchain(arr,size)<<endl;
 
    
    return 0;
}

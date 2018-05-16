#include<iostream>
using namespace std;

int longestAP(int arr[],int n){
	if(n<=2)
		return n;
	int L[n][n];
	int llap=2;
	for(int i=0;i<n;i++)     //Last column is set as 2,because if the second word itself is in the last column then the max AP lenght is 2 !
		L[i][n-1]=2;
	for(int j=n-2;j>=1;j--){       //j=0 will have no AP and j=n-1 already taken care of
		int i=j-1;
		int k=j+1;
		while(i>=0 && k<=n-1){               
			if(arr[i]+arr[k]<2*arr[j]){
				k++;
			}
			else if(arr[i]+arr[k]>2*arr[j])
			{
				L[i][j]=2;       //we have to set the array in this because we are filling bottom wards
				i--;        
			}
			else {
				L[i][j]=L[j][k]+1;
				llap=max(llap,L[i][j]);
				i--;
				k++;

			}
		}
		while(i>=0){
			L[i][j]=2;
			i--;
		}
	}
	return llap;
}

int main()
{
    int set1[] = {1, 7, 10, 13, 14, 19};
    int n1 = sizeof(set1)/sizeof(set1[0]);
    cout <<   longestAP(set1, n1) << endl;
 
    int set2[] = {1, 7, 10, 15, 27, 29};
    int n2 = sizeof(set2)/sizeof(set2[0]);
    cout <<   longestAP(set2, n2) << endl;
 
    int set3[] = {2, 4, 6, 8, 10};
    int n3 = sizeof(set3)/sizeof(set3[0]);
    cout <<   longestAP(set3, n3) << endl;
 
    return 0;
}
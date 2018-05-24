#include<bits/stdc++.h>
using namespace std;

int lasc(int arr[],int n){
	int las[n][2];
	memset(las,1,sizeof(las));
	int res=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i] && las[i][0]<las[j][1]+1)
				las[i][0]=las[j][1]+1;
			if(arr[j]>arr[i] && las[i][1]<las[j][0]+1)
				las[i][1]=las[j][0]+1;

		}
		if(res<max(las[i][0],las[i][1]))
			res=max(las[i][0],las[i][1]);


	}

	return res;


}
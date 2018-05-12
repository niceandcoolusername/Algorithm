#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& arr, int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void printbitonic(int arr[],int n){

	vector<vector<int>> LIS(n);

	LIS[0].push_back(arr[0]);

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i] && LIS[j].size()>LIS[i].size())
				LIS[i]=LIS[j];
		}
		LIS[i].push_back(arr[i]);
	}

	vector<vector<int>> LDS(n);

	LDS[n-1].push_back(arr[n-1]);

	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[j]<arr[i] && LDS[j].size()>LDS[i].size())
				LDS[i]=LDS[j];
		}
		LDS[i].push_back(arr[i]);
	}

	for(int i=0;i<n;i++)
		reverse(LDS[i].begin(),LDS[i].end());
	int max=0;
	int max_index=-1;

	for(int i=0;i<n;i++){
		if(LDS[i].size()+LIS[i].size()-1>max){
			max=LDS[i].size()+LIS[i].size()-1;
			max_index=i;
		}
	}

	print(LIS[max_index],LIS[max_index].size()-1);
	print(LDS[max_index],LDS[max_index].size());


}

int main()
{
    int arr[] = { 1, 11, 2, 10, 4, 5, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printbitonic(arr, n);
    return 0;
}
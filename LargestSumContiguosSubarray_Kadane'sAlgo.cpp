#include<bits/std++.h>
using namespace std;

int maxarray(int arr[],int n){
	int max_ending_here=max_so_far=0;
	for(int i=0;i<size;i++){
		max_ending_here=max_ending_here+size[i];
		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
		if(max_ending_here<0)
			max_ending_here=0;

	}
	return max_so_far;
}

int main(){
	int a[]={-2,-3,4,-1,,-2,1,5,-3};
	int n=8;
	int max_sum=maxarray(a,n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

class ret{      //multiple_values_return_krne_ke_liye_banaya
public:
	int start,end,max_sum;
};

ret maxarray(int arr[],int size){
	int max_ending_here=0;
	int max_so_far=INT_MIN;
	int start=0,end=0,s=0;
	for(int i=0;i<size;i++){
		max_ending_here=max_ending_here+arr[i];
		if(max_so_far<max_ending_here){
			start=s;
			end=i;
			max_so_far=max_ending_here;}
		if(max_ending_here<0){
			s=i+1;
			max_ending_here=0;}

	}
	ret r;
	r.start=start;
	r.end=end;
	r.max_sum=max_so_far;
	return r;
}

int main(){
	int a[]={-2,-3,4,-1,-2,1,5,-3};
	int n=8;
	
	ret k;
	k=maxarray(a,n);
	cout<<"max sum "<<k.max_sum<<endl;
	cout<<"start and end index : "<<k.start<<" "<<k.end<<endl;
	return 0;
}

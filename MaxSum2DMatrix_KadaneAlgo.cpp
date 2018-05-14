#include<bits/stdc++.h>
#define ROW 4
#define COLUMN 5
using namespace std;

class ret{      //multiple_values_return_krne_ke_liye_banaya
public:
	int start,end,max_sum;
};

ret maxarray(int arr[],int size){
	int max_ending_here=0;
	int max_so_far=INT_MIN;
	int start=0,end=0,s=0;
	for(int i=0;i<size;i++){                                   //ye 1D wala kadane hai ,jo maine khud se banaya tha 
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


void kadane(int arr[][COLUMN]){
	ret k;
	int current_sum=INT_MIN;
	int max_sum=INT_MIN;
	int max_left,max_right,max_top,max_down;

	int temp[ROW];

	for(int i=0;i<COLUMN;i++){
		for(int k=0;k<ROW;k++){
            temp[k]=arr[k][i];}
        for(int j=i+1;j<COLUMN;j++){                //Direct implementation of Tushar Roy's video!
        	for(int k=0;k<ROW;k++){
        		temp[k]=temp[k]+arr[k][j];
        	}
        	k=maxarray(temp,ROW);     //k is the class ret which will take the return value of 1D kadane 
        	current_sum=k.max_sum;
        	if(current_sum>max_sum)
        		{max_sum=current_sum;
        		max_left=i;
        		max_right=j;
        		max_top=k.start;
        		max_down=k.end;
                                    
                               }
        }

	}
	cout<<"max left & right:"<<max_left<<" "<<max_right<<endl;  //Use 1D kadane with dimensions to return max_top and max_bottom indices!
	cout<<"max top & down:"<<max_top<<" "<<max_down<<endl;
	cout<<"max sum "<<max_sum;
}



	int main()
{
    int M[ROW][COLUMN] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
 
    kadane(M);
 
    return 0;

}
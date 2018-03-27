#include<iostream>
#include<math.h>

using namespace std;

class point{
	int x;
	int y;
public:
	void set_values(int a ,int b)
	{
		x=a;
		y=b;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}

};

float min(float a,float b)
{
	if(a>=b){return b;}
	if(b>a){return a;}
}
void swap(point A[],int a, int  b)
{
    int temp1=A[a].getx();
    int temp2=A[a].gety();
    A[a].set_values(A[b].getx(),A[b].gety());
    A[b].set_values(temp1,temp2);
}

float distance(point A[],int a,int b){
	float d=sqrt(((A[a].getx()-A[b].getx())*(A[a].getx()-A[b].getx()))+((A[a].gety()-A[b].gety())*(A[a].gety()-A[b].gety())));
	return d;
} 

int partition_x(point A[], int low, int high){
	
	int i=low-1;
	int j;
	for(int j=low;j<=high-1;j++)
	{
		if(A[j].getx()<=A[high].getx())
		{
			i++;
			swap(A,i,j);

		}

		swap(A,i+1,high);
		return (i+1);
	}


}

void quicksort_x(point A[],int low,int high){

	if(high>low){
		int p=partition_x(A,low,high);
		quicksort_x(A,low,p-1);
		quicksort_x(A,p+1,high);
	}
}

int partition_y(point A[], int low, int high){
	
	int i=low-1;
	int j;
	for(int j=low;j<=high-1;j++)
	{
		if(A[j].gety()<=A[high].gety())
		{
			i++;
			swap(A,i,j);

		}

		swap(A,i+1,high);
		return (i+1);
	}


}

void quicksort_y(point A[],int low,int high){

	if(high>low){
		int p=partition_y(A,low,high);
		quicksort_y(A,low,p-1);
		quicksort_y(A,p+1,high);
	}
}



float stripmin(point strip[],int size,float delta)
{	
	quicksort_y(strip,0,size-1);
	for(int j=0;j<size;++j)
	{
		for(int i=j+1;i<size && abs(strip[i].gety()-strip[j].gety())<delta ;++i)
			
		{
			if(distance(strip,i,j)<delta)
			{
				delta=distance(strip,i,j);
				

			}
		}
	}
return delta;

}


double mindist(point A[],int low,int high)
{
if(high-low==1){
	return distance(A,low,high);
}
if (high-low==0){
	return 1000000000000000;
	//So high value that is not considered
}
else{
   
	int mid=(low+high)/2;
	float l=mindist(A,low,mid-1);
	float r=mindist(A,mid+1,high);

	
	double delta=min(l,r);

	point strip[high-low+1];
	int j=0;
	for(int i=0;i<high-low+1;i++)
	{
		if(abs(A[i].getx()-A[(int)mid].getx())<delta)
		{
			strip[j]=A[i];
			j++;
			//So j is the lenght of the strip
		}
	}

	return min(delta,stripmin(strip,j,delta));
	}
}



int main(){
	int n;
	cin>>n;
	if(n<=1)
		{cout<<"Not possible for given number of points"<<endl; return 1;}

	point A[n];
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		A[i].set_values(x,y);
	}
	quicksort_x(A,0,n-1);
	cout<<"The smallest distance is "<<min(mindist(A,0,n-1),distance(A,0,1))<<endl;
	return 0;
}
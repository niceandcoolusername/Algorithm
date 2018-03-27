#include<iostream>
#include<math.h>

using namespace std;

class point{
public:
	int x;
	int y;
};

float min(float a,float b)
{
	if(a>=b){return b;}
	if(b>a){return a;}
}
void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

float distance(point A[],int a,int b){
	float d=sqrt(((A[a].x-A[b].x)*(A[a].x-A[b].x))+((A[a].y-A[b].y)*(A[a].y-A[b].y)));
	return d;
} 

int partition_x(point A[], int low, int high){
	
	int i=low-1;
	
	for(int j=low;j<=high-1;j++)
	{
		if(A[j].x<=A[high].x)
		{
			i++;
			swap(A[i].x,A[j].x);
			swap(A[i].y,A[j].y);

		}

		swap(A[i+1].x,A[high].x);
		swap(A[i+1].y,A[high].y);
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
	
	for(int j=low;j<=high-1;j++)
	{
		if(A[j].y<=A[high].y)
		{
			i++;
			swap(A[i].x,A[j].x);
			swap(A[i].y,A[j].y);

		}

		swap(A[i+1].x,A[high].x);
		swap(A[i+1].y,A[high].y);
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
		for(int i=j+1;i<size && (strip[i].y-strip[j].y)<delta ;++i)
			
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
		if(abs(A[i].x-A[(int)mid].x)<delta)
		{
			strip[j]=A[i];
			j++;
			//So j is the lenght of the strip
		}
	}

	return min(delta,stripmin(strip,j,delta));
	}
}

float closestpair(point A[],int n)
{
	quicksort_x(A,0,n-1);
	return mindist(A,0,n-1);
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
		A[i].x=x;
		A[i].y=y;
	}
	
	cout<<"The smallest distance is "<<min(closestpair(A,n),distance(A,0,1))<<endl;
	cout<<A[0].x<<A[1].x<<A[2].x<<A[3].x<<A[4].x;
	return 0;
}
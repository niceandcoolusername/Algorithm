#include<iostream>
#include<math.h>
#include <ctime>
using namespace std;
int n;

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
	
	for(int j=low;j<=high-1;j++)
	{
		if(A[j].getx()<=A[high].getx())
		{
			i++;
			swap(A,i,j);

		}

		
	}
	swap(A,i+1,high);
	return (i+1);


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
		if(A[j].gety()<=A[high].gety())
		{
			i++;
			swap(A,i,j);

		}

		
	}
	swap(A,i+1,high);
		return (i+1);


}

void quicksort_y(point A[],int low,int high){

	if(high>low){
		int p=partition_y(A,low,high);
		quicksort_y(A,low,p-1);
		quicksort_y(A,p+1,high);
	}
}



float stripmin(point strip[],point A[], int size,float delta)
{	
	quicksort_y(strip,0,size-1);
	for(int j=0;j<size;++j)
	{
		for(int i=j+1;i<size && abs(strip[i].gety()-strip[j].gety())<delta ;++i)
			
		{
			if(distance(strip,i,j)<delta)
			{
				delta=distance(strip,i,j);
				A[n] = strip[i];
				A[n+1]= strip[j];

			}
		}
	}
return delta;

}


double mindist(point A[],int low,int high)
{
if(high-low==1){
	if(distance(A,low,high) < distance(A,n,n+1))
	{
		A[n] = A[low];
		A[n+1] = A[high];
	}
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

	return min(delta,stripmin(strip,A,j,delta));
	}
}



int main(){
	
	n = rand()/(float)RAND_MAX*12;
	if(n<=1)
		{cout<<"Not possible for given number of points"<<endl; return 1;}

	point A[n+2];
	A[n].set_values(0, 0);
	A[n+1].set_values(100, 100);
	for(int i=0;i<n;i++)
	{
		int x,y;
		x = rand()/(float)RAND_MAX*10;
		y = rand()/(float)RAND_MAX*10;
		A[i].set_values(x,y);
		cout <<x <<" "<<y<<"\n";
	}
	time_t tstart , tend;
    tstart = clock();
	quicksort_x(A,0,n-1);
	cout<<"The smallest distance is "<<min(mindist(A,0,n-1),distance(A,0,1))<<endl;
	cout <<"closest points are ("<<A[n].getx()<<", "<<A[n].gety()<<")"<<" "<<"("<<A[n+1].getx()<<", "<<A[n+1].gety()<<")"<<"\n";
	tend = clock();
	cout <<"timetaken"<<(double)(tend - tstart) /((double)CLOCKS_PER_SEC)<<" sec"<<"\n";
	//cout<<A[0].getx()<<A[1].getx()<<A[2].getx()<<A[3].getx()<<A[4].getx();
	return 0;
}
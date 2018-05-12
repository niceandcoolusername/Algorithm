#include<iostream>
using namespace std;

struct Box{

int w,d,h;

};
int compare (const void *a, const void * b)
{                                                         //Standard format for qsort!
    return ( (*(Box *)b).d * (*(Box *)b).w ) -
           ( (*(Box *)a).d * (*(Box *)a).w );
}
int maxheight(Box arr[],int n){

	Box rot[3*n];

	int index=0;
	for(int i=0;i<n;i++){
		rot[index].h=arr[i].h;
		rot[index].w=min(arr[i].w,arr[i].d);
		rot[index].d=max(arr[i].w,arr[i].d);
		index++;
                        
		rot[index].h=arr[i].d;
		rot[index].w=min(arr[i].w,arr[i].h);
		rot[index].d=max(arr[i].w,arr[i].h);
		index++;

		rot[index].h=arr[i].w;
		rot[index].w=min(arr[i].h,arr[i].d);
		rot[index].d=max(arr[i].h,arr[i].d);
		index++;

}
n=3*n;
qsort(rot,n,sizeof(rot[0]),compare);

int msh[n];
for(int i=0;i<n;i++){
	msh[i]=rot[i].h;
}
for(int i=1;i<n;i++){
	for(int j=0;j<i;j++){
		if(rot[j].w>rot[i].w && rot[j].d>rot[i].d && msh[i]<msh[j]+rot[i].h)
			msh[i]=msh[j]+rot[i].h;
		
	}
}
int max=-1;
for(int i=0;i<n;i++){
	if(max<msh[i])
		max=msh[i];
}
return max;

}


int main()
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);
 
  cout<<"The maximum possible height of stack is"<<maxheight(arr,n)<<endl;
 
  return 0;
}
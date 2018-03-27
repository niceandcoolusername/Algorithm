#include<iostream>
using namespace std;

class complex{

float a;
float b;
float norm;

public:
complex(){
cin>>a>>b;
norm=a*a+b*b;}



complex(float x,float y){

a=x;
b=y;
norm=a*a+b*b;
}

bool operator< (complex x){
if(norm<x.norm) return true;
else return false;

}


void display(){cout<<a<<"+ j"<<b<<endl;}
int partition(complex arr[],int low,int high){

complex pivot=arr[high];
int i=low-1;

for(int j=0;j<=high-1;j++){

if(arr[j]<pivot){
i++;

complex t= arr[j];
arr[j]=arr[i];
arr[i]=t;

}

}
complex t2= arr[i+1];
arr[i+1]=arr[high];
arr[high]=t2;
return (i+1);

}

void quicksort(complex arr[],int low,int high){
if(low<high)
{

int pi=partition(arr,low,high);
 quicksort(arr,low,pi-1);
quicksort(arr,pi+1,high);


}

}



};









int main(){
cout<<"Enter n"<<endl;

int n;
cin>>n;
cout<<"Enter "<<n<<" complex values one by one"<<endl;

complex A[n];

A[n].quicksort(A,0,n-1);
cout<<"Sorted values are"<<endl;
for(int i=0;i<n;i++){

A[i].display();


}




return 0;

}

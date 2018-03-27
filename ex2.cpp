#include <bits/stdc++.h>

using namespace std;

struct point 
{
	int x;
	int y;
};

// **************************************SORTING********************************************
int two_way_partition(point arr[],int p,int r)
{
	
	int i = p-1;

	for(int j = p; j < r ;j++)
	{
		if(arr[j].x < arr[r].x)
		{
			i++;
			swap(arr[i].x, arr[j].x);
			swap(arr[i].y, arr[j].y);
		}
	}
	swap(arr[i+1].x, arr[r].x);
	swap(arr[i+1].y, arr[r].y);
	return i+1;
};



void Quick_Sort(point arr[],int p,int r)
{
	if(p<r)
	{
		int k=two_way_partition(arr,p,r);
		Quick_Sort(arr,p,k-1);
		Quick_Sort(arr,k+1,r);
	}
};

//***************************************************************************************************

int two_way_partition_y(point arr[],int p,int r)
{
	
	int i = p-1;

	for(int j = p; j < r ;j++)
	{
		if(arr[j].y < arr[r].y)
		{
			i++;
			swap(arr[i].x, arr[j].x);
			swap(arr[i].y, arr[j].y);
		}
	}
	swap(arr[i+1].x, arr[r].x);
	swap(arr[i+1].y, arr[r].y);
	return i+1;
};



void Quick_Sort_y(point arr[],int p,int r)
{
	if(p<r)
	{
		int k=two_way_partition_y(arr,p,r);
		Quick_Sort(arr,p,k-1);
		Quick_Sort(arr,k+1,r);
	}
};

//********************************************************************************************************


 // *****************************************DISTANCE************************************************
double dist (point arr[], int p, int r)
{
	double d = sqrt(pow((arr[p].x-arr[r].x),2) + pow((arr[p].y-arr[r].y),2));
	return d;
};




// ********************************************MAINQUES*********************************************
double mindelt(point arr[], int p,int r,double delta)
{
	int mid = (p+r)/2,low = -1 ,high=-1 ;
	for (int i= p; i <= mid ;i++)
	{

		if (abs(arr[i].x - arr[mid].x) < delta)
		{
			low = i;
			break;
		}
		
	}
	//cout << low <<"fg"<<"\n";
	if(low == -1)return 1000000000;

	for (int i= r; i >= mid+1	 ;i--)
	{

		if(abs(arr[i].x - arr[mid].x) < delta)
		{
			high = i;
			break;
		}
		
	}
	if(high == -1)return 1000000000;

	//cout << high <<"fg"<<"\n";
	//cout << mid <<"fg"<<"\n";
	double temp = delta;
	point temparr1[mid-low+3] ;
	point temparr2[r -mid +2] ;

	for(int i= 0 ;i<= mid-low ;i++)
	{
		temparr1[i].x = arr[i+low].x;
		temparr1[i].y = arr[i+low].y;
	}
	Quick_Sort_y(temparr1 , 0 ,mid-low);

	for(int i= 0 ;i<= high-mid-1 ;i++)
	{
		temparr2[i].x = arr[i+mid+1].x;
		temparr2[i].y = arr[i+mid+1].y;
	}
	Quick_Sort_y(temparr2, 0 , high-mid-1);

	
	for(int i=0; i<= mid-low ;i++)
	{
		int index = high-mid-1;
		for (int j = 0; j <= high-mid-1 ;j++)
		{
			if(temparr1[i].y <= temparr2[j].y)
			{
				index = j;
				break;
			}
		}
		int t=0;
		while(index +t <= high-mid-1 && t<=2)
		{
			temp = min(temp, sqrt(pow((temparr2[index+t].x-temparr1[i].x),2) + pow((temparr2[index+t].y-temparr1[i].y),2)));
			t++;
		}
		t = 0;
		while(index-t >= 0 && t<= 3)
		{
			temp = min(temp, sqrt(pow((temparr2[index-t].x-temparr1[i].x),2) + pow((temparr2[index-t].y-temparr1[i].y),2)));
			t++;
		}
	}



	for(int i=0; i<= high-mid-1 ;i++)
	{
		int index = mid-low;
		for (int j = 0; j <= mid-low ;j++)
		{
			if(temparr2[i].y <= temparr1[j].y)
			{
				index = j;
				break;
			}
		}
		int t=0;
		while(index+t <= mid-low && t<2)
		{
			temp = min(temp, sqrt(pow((temparr1[index+t].x-temparr2[i].x),2) + pow((temparr1[index+t].y-temparr2[i].y),2)));
			t++;
		}
		t = 0;
		while(index-t >= 0 && t<= 3)
		{
			temp = min(temp, sqrt(pow((temparr1[index-t].x-temparr2[i].x),2) + pow((temparr1[index-t].y-temparr2[i].y),2)));
			t++;
		}
	}


	//cout <<temp<<" "<<p<<"to"<<r<<":"<<"low"<<low<<" "<<"high"<<high<<" "<<"\n"; 

	return temp;

};





double mindistance(point arr[], int p, int r)
{
	float mid ,t1,t2;
	if (r - p == 1)
	{
		
		return dist(arr,p,r);
	}

	if (r - p < 1)
	{
		return 1000000000;
	}

	else
	{
		//cout <<"Welcome"<<"\n";
		 mid = (p+r)/2;
		//cout <<"dfsdf"<<mid<<"\n\n";
		t1 = mindistance(arr, p, mid);
		//cout <<t1<<"\n";
		 t2 = mindistance(arr, mid+1, r);
		//cout <<t2<<"\n";
	}
		double delta = min(t1, t2);
		//cout <<delta<<"dgfdsf"<<"\n";
		return min(delta , mindelt(arr,p,r,delta));
		
}

//******************************************************************************************************************************


int main()
{
	int n;
	cin >>n;
	point arr[n], brr[n];
	for(int i=0; i < n ;i++)
	{
		int a ,b; 
		cin >> a >> b;
		arr[i].x = a;
		arr[i].y = b;
		
	}

	Quick_Sort(arr , 0 , n-1);
	//cout << arr[0].x <<arr[0].y<<"   "<< arr[1].x <<arr[1].y<<"\n";
	cout << mindistance(arr, 0, n-1);
	return 0;
}
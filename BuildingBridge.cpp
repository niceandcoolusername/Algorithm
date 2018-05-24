#include<bits/stdc++.h>
using namespace std;

struct city{
	int north,south;

};

bool compare(struct city a,struct city b){
	if(a.south==b.south)
		return a.north<b.north;
	return a.south<b.south;
}


int maxbridge(struct city values[],int n){

	int lis[n];
	for(int i=0;i<n;i++)
		lis[i]=1;

	sort(values,values+n,compare);

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(values[i].north>=values[j].north && lis[i]<lis[j]+1)
				lis[i]=1+lis[j];

		}
	}
	int max=lis[0];
	for(int i=1;i<n;i++){
		if(max<lis[i])
			max=lis[i];
	}
	return max;
}

int main()
{
    struct city values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    int n = 4;
    cout << "Maximum number of bridges = "
             << maxbridge(values, n);    
    return 0;
} 
#include<iostream>
using namespace std;
#define NO_OF_CHARS 256

int ncrs(string str,int n){
	int n=str.length();
	int cur_len=1;
	int max_len=1;
	int pev_index;
	int i;
	int visited=new int [sizeof(int *NO_OF_CHARS)];
	for(int i=0;i<NO_OF_CHARS;i++){
		visited[i]=-1;

	}
	visited[str[0]]=0;

	for(int i=1;i<n;i++){
		prev_index=visited[str[i]];
		if(prev_index==-1 || i-cur_len>prev_index)
			cur_len++;

	else{
		if(cur_len>max_len)
			max_len=cur_len;
		cur_len=i-prev_index;
	}
	visited[str[i]]=i;
	}
	if(cur_len>max_len)
		max_len=cur_len;
	free(visited);

	return max_len;
}


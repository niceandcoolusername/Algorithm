#include<iostream>
#include<list>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
public:
	void DFSU(int v,bool visited[]){
		visited[v]=true;
		cout<<v<<endl;
		list<int>::iterator i;
		for(i=adv[v].begin();i!=adv[v].end();i++){
			if(!visited[*i]){
				DFSU(*i,visited);
			}
		}
	}

	void DFS(int s){
		bool *visited=new bool[V];
		for(int i=0;i<V;i++)
			visited[i]=false;
		DFSU(v,visited);
	}
};
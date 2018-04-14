#include<iostream>
#include<bits/stdc++.h>


using namespace std;
typedef pair<int, int> iPair;


class Graph{
	int V;
	list<pair<int,int>> *adj;
public:
	Graph(int V);
	void addEdge(int u,int v,int w);
	void PrimMST();
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<pair<int,int>>[V];
}

void Graph::addEdge(int u,int v,int w){
	adj[u].push_back(make_pair(v,w));      //If v has u in his lists then u must also have v in his lists !
 	adj[v].push_back(make_pair(u,w));
}

void Graph::PrimMST(){
int src=0;
priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
vector<bool> MSTset(V,false);
vector<int> Parent(V,-1);
vector<int>key(V,INT_MAX);

pq.push(make_pair(0,src));
key[src]=0;

while(!pq.empty()){

int u=pq.top().second;
pq.pop();

MSTset[u]=true;

list<pair<int,int>>::iterator i;
for(i=adj[u].begin();i!=adj[u].end();i++){
	int v=(*i).first;
	int weight=(*i).second;
	if(MSTset[v]==false && key[v]>weight){
		key[v]=weight;
		pq.push(make_pair(key[v],v));
		Parent[v]=u;

	}
}

}

for(int i=1;i<V;i++){
	cout<<Parent[i]<<" "<<i<<endl;
}
}

int main()
{
   
    int V = 9;
    Graph g(V);
 
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.PrimMST();
 
    return 0;
}
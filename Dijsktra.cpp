#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(int distance[],bool spt[]){
	int min=INT_MAX;
	int min_index;
	for(int v=0;v<V;v++){
		if(spt[v]==false && distance[v]<=min){
			min=distance[v];
			min_index=v;
		}}
		return min_index;}

void printDist(int distance[],int n){
	for(int i=0;i<n;i++){
		cout<<i<<" "<<distance[i]<<endl;
	}
}

void dijkstra(int graph[V][V],int src){
	 bool spt[V];
	 int distance[V];

	 for(int v=0;v<V;v++){
	 	spt[v]=false;
	 	distance[v]=INT_MAX;
	 }
	 distance[src]=0;
	 for(int count=0;count<V-1;count++){
	 	int u=minDistance(distance,spt);
	 	spt[u]=true;
	 	for(int i=0;i<V;i++){
	 		if(!spt[i] && graph[u][i] && distance[u]+graph[u][i]<distance[i] && distance[u] !=INT_MAX){
	 			distance[i]=distance[u]+graph[u][i];
	 		}
	 	}
	 }
printDist(distance,V);
}

int main()

{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
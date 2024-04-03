//Í¼µÄDFS

#include<iostream>
using namespace std;

void DFSTraverse(Graph g){
	for(v=0;v<g.vexnum;v++){
		visited[i]=false;
	}
	for(v=0;v<g.vexnum;v++) {
		if(!visited[i]){
			DFS(g,v);
		}
	}
}

void DFS(Graph g,int v){
	visit(v);
	visited[v]=true;
	for(w=FirsNeighbor(g,v);w>=0;w=NextNeighbor(g,v,w)){
		if(!visited[w]){
			DFS(g,w);
		}
	}
}

int main(){
	
	return 0;
} 



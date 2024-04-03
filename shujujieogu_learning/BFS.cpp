//图的BFS

#include<iostream>
using namespace std;


void BFSTraverse(Graph g){
	for(i=0;i<g.vexnum;i++){
		visited[i]=false;
	}
	
	for(i=0;i<g.vexnum;i++){ //循环次数为连通图数量 
		if(!visited[i]) {
			BFS(g,i);
		}
	}
}

void BFS(Graph g,int v){
	QueueList Q;
	InitQueue(Q);
	visit(v);
	visited[v]=true;
	Enqueue(Q,v);
	while(!isEmpty(Q)){
		DeQueue(Q,x);//出队的元素赋值给x; 
		for(w=FisrtNeighbor(g,x);w>=0;w=NextNeighbor(g,x,w)){
			if(!visited[w]){
				visit(w);
				visited[w]=true;
				EnQueue(Q,w); 
			} 
		}
	}
}


int main(){
	
	return 0;
} 



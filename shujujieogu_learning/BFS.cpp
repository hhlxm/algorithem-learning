//ͼ��BFS

#include<iostream>
using namespace std;


void BFSTraverse(Graph g){
	for(i=0;i<g.vexnum;i++){
		visited[i]=false;
	}
	
	for(i=0;i<g.vexnum;i++){ //ѭ������Ϊ��ͨͼ���� 
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
		DeQueue(Q,x);//���ӵ�Ԫ�ظ�ֵ��x; 
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



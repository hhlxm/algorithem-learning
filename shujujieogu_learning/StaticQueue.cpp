//静态队列 
#include<iostream>
using namespace std;

#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int front,rear;	//存储队头，队尾的下标
	int size;
} SqQueue;

void InitQueue(SqQueue &Q) {
	Q->rear=Q->front=0;
	Q->size=0;
}

bool QueueEmpty(SqQueue Q) {
	if(Q->size==0) {
		return true;
	}
	return false;
}

bool QueueFull(SqQueue Q) {
	if(Q->size==MaxSize) {
		return true
	}
	return false;
}

bool EnQueue(SqQueue &Q,int x) {
	if(QueueFull(Q)) {
		return false;
	}
	Q->data[Q->rear]=x;
	Q->rear=(Q->rear+1)%MaxSize;
	Q->size++;
	return true;
}

bool OutQueue(SqQueue &Q,int &x){
	if(QueueEmpty(Q)){
		return false;
	}
	x=Q->data[Q->front];
	Q->front=(Q->front+1)%MaxSize;
	Q->size--;
	return true;
}

bool GetHead(SqQueue Q,int &x){
	if(QueueEmpty(Q)){
		return false;
	} 
	x=Q->data[Q->front];
	return true;
} 



int main() {
	SqQueue Q;
	InitQueue(Q);
	return 0;
}

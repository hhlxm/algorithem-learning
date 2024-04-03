//链式队列
#include<iostream>
using namespace std;

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
} LinkNode;

typedef struct {
	LinkNode *front,*rear;
} LinkQueue;

//初始化队列
void InitQueue(LinkQueue& Q) {
	Q.front=NULL;
	Q.rear=NULL;
}

bool EnQueue(LinkQueue& Q,int x) {
	LinkNode *p=new LinkNode;
	p->data=x;
	p->next=NULL;
	if(Q.front==NULL) {
		Q.front=p;
		Q.rear=p;
	} else {
		Q.rear->next=p;
		Q.rear=p;
	}

	return true;
}

bool DeQueue(LinkQueue& Q,int &x) {
	if(Q.front==NULL) {
		return false;
	}
	LinkNode*p=Q.front;
	x=p->data;
	Q.front=p->next;
	delete p;
	return true;
}


//
////初始化队列
//void InitQueue(LinkQueue &Q){
//	Q->front=Q->rear=new LinkNode;	//头结点
//	Q->front->next=NULL;
//}
//
//bool EnQueue(LinkQueue &Q,int x){
//	LinkNode *p=new LinkNode;
//	p->data=x;
//	p->next=NULL;
//	Q->rear->next=p;
//	Q->rear=p;
//	return true;
//}
//
//bool DeQueue(LinkQueue &Q,int &x){
//	if(Q->front==Q->rear){
//		return false;
//	}
//	LinkNode *p=Q->front->next;
//	x=p->data;
//	Q->front->next=p->next;
//	if(Q->rear==p){
//		Q->rear=Q->front;
//	}
//	delete p;
//	return true;
//}

void print_func(LinkQueue Q) {
	LinkNode*p=Q.front;
	while(p!=NULL) {
		cout<<p->data<<endl;
		p=p->next;
	}
}

int main() {
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q,12);
	EnQueue(Q,13);
	print_func(Q);
	int x;
	DeQueue(Q,x);
	print_func(Q);
	return 0;
}

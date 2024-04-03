//������������
#include<iostream>
using namespace std;


typedef struct TreadNode{
	int data;
	struct TreadNode *lchild,*rchild;
	int ltag,rtag;
}TreadNode,*TreadTree;


void visit(TreadNode *q,TreadTree &pre);

//������� 
void InTread(TreadTree T,TreadTree &pre){
	if(T!=NULL){
		InTread(T->lchild,pre);
		visit(T,pre);
		InTread(T->rchild,pre); 
	}
}

void visit(TreadNode *q,TreadTree &pre){

	if(q->lchild==NULL){
		q->lchild=pre;
		q->ltag=1;
	}
	if(pre!=NULL&&pre->rchild==NULL){
		pre->rchild=q;
		pre->rtag=1;
	}
	pre=q;
}

void CreateInTread(TreadTree T){
	TreadNode *pre=NULL; 
	if(T!=NULL){
		InTread(T,pre);
		if(pre->rchild==NULL){
			pre->rtag=1;
		}
	}
}
//������ǰ��
//���ҵĽڵ� 
TreadNode* LastNode(TreadNode* p){
	while(p->rtag==0) p=p->rchild;
	return p;
}
//���� 
TreadNode* PriorNode(TreadNode* p){
	if(p->ltag==1) return p->lchild;
	else return LastNode(p->lchild) 
} 

//��������
//����Ľڵ� 
TreadNode *FirstNode(TreadNode* p){
	while(p->ltag==0) p=p->lchild;
	return p;
} 
//���� 
TreadNode *NextNode(TreadNode *p){
	if(p->rtag==1)	return p->rchild;
	else return FirstNode(p->rchild);
} 

int main(){
	
	
	return 0;
}

//����������ʽ�洢
#include<iostream>
using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchile,*rchild;
}BiTNode,*BiTree;

//��ʼ�� 
bool InitBiTree(BiTree &T){
	T=new BiTNode;
	if(T==NULL){
		return false;
	}
	T->data=1;
	T->lchile=NULL;
	T->rchild=NULL;
	return true; 
}

//���� 
bool InsertBiTNode(BiTree &T,int elem){
	BiTNode *p=new BiTNode;
	if(p==NULL){
		return false;
	}
	p->data=elem;
	p->lchile=NULL;
	p->rchild=NULL;
	T->lchile=p;
	return true; 
}

int visit(BiTree T){
	return T->data;
} 

//�������
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchile);
		PreOrder(T->rchild);
	}
}


//�������
void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchile);
		visit(T);
		InOrder(T->rchild);
	}
}

//�������
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchile);
		PostOrder(T->rchild);
		visit(T);
	}
}
 
//�������(ʹ�ö���) 

 
int main(){
	BiTree T;
	InitBiTree(T); 
	InsertBiTNode(T,4);
	return 0;
	
} 

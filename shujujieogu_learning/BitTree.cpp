//二叉树的链式存储
#include<iostream>
using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchile,*rchild;
}BiTNode,*BiTree;

//初始化 
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

//插入 
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

//先序遍历
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchile);
		PreOrder(T->rchild);
	}
}


//中序遍历
void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchile);
		visit(T);
		InOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchile);
		PostOrder(T->rchild);
		visit(T);
	}
}
 
//层序遍历(使用队列) 

 
int main(){
	BiTree T;
	InitBiTree(T); 
	InsertBiTNode(T,4);
	return 0;
	
} 

//����������
#include<iostream>
using namespace std;


typedef struct BSTNode {
	int key;
	struct BSTNode *lchild,*rchild;
} BSTNode,*BSTree;

BSTNode* BST_Search(BSTree t,int key) {
	while(t!=NULL&&t->key!=key) {
		if(t->key>key) {
			t=t->lchild;
		} else {
			t=t->rchild;
		}
	}
	return t;
}

bool BST_Insert(BSTree &t,int key) {
	if(t==NULL){
		 t=new BSTNode;
		 if(t==NULL){
		 	return false;
		 }
		 t->key=key;
		 t->lchild=NULL;
		 t->rchild=NULL;
		 return true;
	}
	else if(key<t->key){
		BST_Insert(t->lchild,key);
	}
	else if(key>t->key){
		BST_Insert(t->rchild,key);
	}else{
		return true;//�Ѿ����ڽڵ㣬���سɹ�
	}

	//ѭ���ռ临�Ӷ�O(1)
	
}

//��������ĵ�һ��Ԫ��
BSTNode* BST_Fisrt(BSTree t) {
	if(t==NULL) {
		return NULL;
	}
	while(t->lchild!=NULL) {
		t=t->lchild;
	}
	return t;
}

bool BST_Delete(BSTree &t,int key) {
	if(t==NULL){
		cout<<'���в���ֵΪ'<<key<<'�Ľڵ�'<<endl;
		return false; 
	}
	while(t!=NULL&&t->key!=key) {
		if(key<t->key) {
			return BST_Delete(t->lchild, key);
		} else {
			return BST_Delete(t->rchild, key);
		}
	}
	
	
	if(t->lchild==NULL) {
		BSTNode* temp=t;
		t=t->rchild;
		delete temp;
	} else if(t->rchild==NULL) {
		BSTNode* temp=t;
		t=t->lchild;
		delete temp;
	} else {
		BSTNode* current=BST_Fisrt(t->rchild);//�������е����������һ��Ԫ�أ�����СԪ�أ�
		t->key=current->key;
		BST_Delete(t,current->key);
	}
	return true;

}

void BST_print(BSTree t){
	if(t==NULL){
		return;
	}
	BST_print(t->lchild);
	cout<<t->key<<endl;
	BST_print(t->rchild); 
}

int main() {
	BSTree T=NULL;
	BST_Insert(T,50);
	BST_Insert(T,66);
	BST_Insert(T,60);
	BST_Insert(T,26);
	BST_Insert(T,21);
	BST_Insert(T,30);
	BST_Insert(T,70);
	BST_Insert(T,68);
	BST_print(T);
	return 0;
}

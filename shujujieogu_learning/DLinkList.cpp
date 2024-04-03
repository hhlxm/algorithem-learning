//双链表
#include<iostream>
using namespace std;
typedef struct DNode {
	int data;
	struct DNode *prior,*next;
} DNode,*DLinkList;

//初始化
bool InitDLinkList(DLinkList &L) {
	L=new DNode;
	if(L==NULL) {
		return false;
	}
	L->prior=NULL;//头结点的prior永远指向NULL
	L->next=NULL;
	return true;
}

//插入(例：s插入p之后)
bool InsertNextDNode(DNode*p,DNode *s) {
	if(p==NULL||s==NULL) {
		return false;
	}
	s->next=p->next;
	if(p->next!=NULL) {
		p->next->prior=s;
	}
	s->prior=p;
	p->next=s;
}

//删除
int DeleteDNode(DNode*p) {
	if(p->next!=NULL) {
		p->next->prior=p->prior;
	}
	p->prior->next=p->next;
	delete p;
	return p->data;

}

//销毁链表
void DestoryList(DLinkList L){
	while(L->next!=NULL){
		DeleteDNode(L->next);
	}
	delete L;
	L=NULL;
}

int main() {


	return 0;
}

//˫����
#include<iostream>
using namespace std;
typedef struct DNode {
	int data;
	struct DNode *prior,*next;
} DNode,*DLinkList;

//��ʼ��
bool InitDLinkList(DLinkList &L) {
	L=new DNode;
	if(L==NULL) {
		return false;
	}
	L->prior=NULL;//ͷ����prior��Զָ��NULL
	L->next=NULL;
	return true;
}

//����(����s����p֮��)
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

//ɾ��
int DeleteDNode(DNode*p) {
	if(p->next!=NULL) {
		p->next->prior=p->prior;
	}
	p->prior->next=p->next;
	delete p;
	return p->data;

}

//��������
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

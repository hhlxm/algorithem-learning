//������
#include<iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode,*LinkList; //*LinkList�൱����һ���ṹ�壬����LinkList����ָ�룬һ��������ʾͷָ��


//����һ��������,����ͷ�ڵ�
bool InitList(LinkList &L) {
	L=new LNode;	//Lָ��ͷ�ڵ�
	if(L==NULL) {
		return false;
	}
	L->next=NULL;
	return true;
}

//���ҽڵ�
LNode * GetElem(LinkList L,int loc) {
	if(loc<0) {
		return NULL;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL&&j<loc) {
		p=p->next;
		j++;
	}
	return p;
}
//ָ���ڵ���� (���)
bool InsertNextNode(LNode *p,int elem) {
	if(p==NULL) {
		return false;
	}
	LNode *s=new LNode;
	if(s==NULL) {
		return false;
	}
	s->data=elem;
	s->next=p->next;
	p->next=s;
	return true;
}

//ָ���ڵ����(ǰ��)
bool InsertPriorNode(LNode *p,int elem) {
	if(p==NULL) {
		return false;
	}
	LNode *s=new LNode;
	if(s==NULL) {
		return false;
	}
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->data=elem;
	return true;
}

//��λ�����
bool ListInsert(LinkList L,int loc,int elem) {
	LNode*p=GetElem(L,loc-1);
	if(p==NULL) {
		return false;
	}
	return InsertNextNode(p,elem);
}



//ɾ���ڵ�
bool ListDelete(LinkList &L,int loc,int &elem) {
	if(loc<1) {
		return false;
	}
	LNode *p = L;
	int j=0;
	while(p!=NULL&&j<loc-1) {
		p=p->next;
		j++;
	}
	if(p==NULL||p->next==NULL) {
		return false;
	}

	LNode *q=p->next;
	elem=q->data;
	p->next=q->next;
	delete q;
	return true;
}



//�󳤶�
int Length(LinkList L) {
	int len=0;
	LNode *p=L;
	while(p->next!=NULL) {
		p=p->next;
		len++;
	}
	return len;
}

void func_print(LinkList L) {
	LNode *p;
	p=L->next;
	while(p!=NULL) {
		cout<<p->data<<endl;
		p=p->next;
	}
}

int main() {
	LinkList L;
	InitList(L);
	int length=0;
	for(int i=0; i<5; i++) {
		ListInsert(L,1,i);
	}
	func_print(L);

	return 0;
}

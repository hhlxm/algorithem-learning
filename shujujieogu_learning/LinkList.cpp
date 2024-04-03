//单链表
#include<iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode,*LinkList; //*LinkList相当于是一个结构体，所以LinkList就是指针，一般用来表示头指针


//定义一个单链表,定义头节点
bool InitList(LinkList &L) {
	L=new LNode;	//L指向头节点
	if(L==NULL) {
		return false;
	}
	L->next=NULL;
	return true;
}

//查找节点
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
//指定节点插入 (后插)
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

//指定节点插入(前插)
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

//按位序插入
bool ListInsert(LinkList L,int loc,int elem) {
	LNode*p=GetElem(L,loc-1);
	if(p==NULL) {
		return false;
	}
	return InsertNextNode(p,elem);
}



//删除节点
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



//求长度
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

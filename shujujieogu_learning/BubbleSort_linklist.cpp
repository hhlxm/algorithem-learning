//冒泡排序（链表）

#include<iostream>
using namespace std;

typedef struct LNode {
	int key;
	LNode *next;
} LNode ,*LinkList;


//不带头结点
void InitList(LinkList &L) {
	L=NULL;
}

bool InsertList(LinkList &L,int elem) {

	LNode *p=new LNode;
	if(p==NULL) {
		return false;
	}
	p->key=elem;

	p->next=L;
	L=p;

	return true;

}

void BubbleSort(LinkList &L,int length) {
	if(L==NULL||L->next==NULL) {
		return;
	}

	int i,j,temp;
	bool flag=false;
	LNode *pj,*pi;
	for(i=length-1; i>0; i--) {
		pj=L;
		pi=pj->next;
		for(j=0; j<i; j++) {
			if(pj->key>pi->key) {
				temp=pj->key;
				pj->key=pi->key;
				pi->key=temp;
				flag=true;
			}
			pj=pj->next;
			pi=pj->next;
		}
		if(flag==false) {
			return;
		}
	}

}

void print_func(LinkList L) {
	LNode *p=L;
	while(p!=NULL) {
		cout<<p->key<<endl;
		p=p->next;
	}
}

int main() {
	LinkList L;
	InitList(L);
	InsertList(L,1);
	InsertList(L,5);
	InsertList(L,2);
	InsertList(L,3);
	InsertList(L,7);
	InsertList(L,3);
	print_func(L);
	BubbleSort(L,6);
	print_func(L);
	return 0;
}

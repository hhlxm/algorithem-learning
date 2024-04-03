//插入排序（链表）

#include<iostream>
using namespace std;


typedef struct DLNode {
	int data;
	struct DLNode *prior,*next;
} DLNode,*DLinkList;

bool InitLink(DLinkList &L) {
	L=new DLNode;
	if(L==NULL) {
		return false;
	}
	L->prior=NULL;
	L->next=NULL;
	return true;
}

bool Insert_sort(DLinkList &L) {
	if(L==NULL) {
		return false;
	}
	if(L->next==NULL) {
		return true;
	}
	DLNode *head=L->next;
	DLNode *p=head->next;
	DLNode *point;
	while(p!=NULL) {
		if(p->data<head->data) {
			head->next=p->next;
			if(head->next != NULL) {
				head->next->prior = head;
			}

			//Initialize point 
			point=L->next;
			while(p->data>point->data) {
				point=point->next;
			}

			p->next=point;
			p->prior=point->prior;

			point->prior->next=p;
			point->prior=p;
			
			p=head->next;//head已经更新 
		} else {
			head=head->next;
			p=head->next;
		}

	}
	return true;
}

void Insert_DLink(DLinkList &L,int x) {
	DLNode*p=new DLNode;
	p->data=x;
	p->next=L->next;
	p->prior=L;
	L->next=p;

}

void print_func(DLinkList L) {
	DLNode *p=L->next;
	while(p!=NULL) {
		cout<<p->data<<endl;
		p=p->next;
	}
}

int main() {
	DLinkList L;
	InitLink(L);
	Insert_DLink(L,1);
	Insert_DLink(L,3);
	Insert_DLink(L,3);
	Insert_DLink(L,6);
	Insert_DLink(L,2);
	Insert_DLink(L,7);
	print_func(L);
	Insert_sort(L);
	print_func(L);
	return 0;
}

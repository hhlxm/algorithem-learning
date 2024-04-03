//链栈
#include<iostream>
using namespace std;

typedef struct Linknode {
	int data;
	struct Linknode *next;

}*LinkStack;


void InitStack(LinkStack &L) {		//不带头结点
	L=NULL;
}

bool Push(LinkStack &L,int x) {
	Linknode *p=new Linknode;
	if(p==NULL) {
		return false;
	}
	p->data=x;
	p->next=L;
	L=p;
	return true;
}

bool Pop(LinkStack &L,int &x) {
	if(L==NULL){
		return false;
	}
	Linknode *p=L;
	x=p->data;
	L=L->next;
	delete p;
	return true;
}

int GetVal(LinkStack L){
	return L->data;
}

bool Empty(LinkStack L){
	if(L==NULL){
		return true;
	}
	return false;
}

void print_func(LinkStack L){
	Linknode *p=L;
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;
	}
}

int main() {
	LinkStack L;
	int x;
	InitStack(L);
	Push(L,2);
	Push(L,3);
	print_func(L);
	
	Pop(L,x);
	cout<<x<<endl;
	cout<<"___________"<<endl;
	print_func(L);
	
	return 0;
}

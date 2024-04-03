//��ѡ������


#include<iostream>
using namespace std;

typedef struct LNode{
	int key;
	LNode *next;
}LNode,*LinkList;


void InitList(LinkList &L){
	L=NULL;
}

bool InsertList(LinkList &L,int elem){
	LNode*p=new LNode;
	if(p==NULL){
		return false; 
	}
	p->key=elem;
	p->next=L;
	L=p;
	
}

void Swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void SimpleSelectSort(LinkList &L){
	if(L==NULL){
		return;
	}
	LNode *p,*q;//p����ָ��Ҫ����СԪ�ص�����,q����ָ��ǰ��Ԫ�� 
	for(p=L;p!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(q->key<p->key){
				Swap(q->key,p->key);//swap current elem and minimum elem(p->key)
			}
		} 
	}
}

void print_func(LinkList L){
	LNode*p;
	p=L;
	for(;p!=NULL;p=p->next){
		cout<<p->key<<endl;
	} 
}

int main(){
	LinkList L;
	InitList(L);
	InsertList(L,1);
	InsertList(L,12);
	InsertList(L,3);
	InsertList(L,4);
	InsertList(L,2);
	InsertList(L,1);
	print_func(L);
	cout<<"---------------------------"<<endl;
	SimpleSelectSort(L);
	print_func(L);
	return 0;
	
} 

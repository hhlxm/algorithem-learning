#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	int num;
	LNode* next;
}LNode;

typedef struct{
	LNode* head;
	LNode* tear;
}LinkList;


void Initial(LinkList &L){
	//不带头结点
	L.head=NULL;
	L.tear=NULL;
}

bool Insert(LinkList &L,int num,int elem){
	LNode *p=new LNode;
	if(p==NULL){
		return false; 
	}
	p->data=elem;
	p->num=num;
	if(L.head==NULL){
		L.head=p;
		L.tear=L.head;
		p->next=L.tear;//构成环 
	}else{
		p->next=L.head;
		L.head=p;
		L.tear->next=L.head;
	} 
	return true;
} 


void delete_LNode(LNode *p){
	LNode* temp = p->next;
	p->data = p->next->data;
	p->num = p->next->num;
	p->next = p->next->next;
	delete temp;
}

void Joseph(LinkList L,int length){
	int i;
	LNode *point;
	cin>>i;
	for(point=L.head;length>1;){
		for(int j=0;j<i;j++){
			point=point->next;
		}
		i=point->data;
		cout<<"Number"<<point->num<<"is kicked off!"<<endl;
		delete_LNode(point);
		length--;
	} 
	cout<<point->num<<"is survived!" ;
} 

//void print_list(LinkList L){
//	LNode *p=L.head;
//	for(int i=0;i<16;i++){
//		cout<<p->num<<endl;
//		p=p->next;
//	}
//} 

int main(){
	LinkList L;
	Initial(L);
	for(int i=0;i<8;i++){
		Insert(L,8-i,3);
	} 
	Joseph(L,8);
//	print_list(L);
	
	return 0;
} 

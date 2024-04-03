//栈在括号匹配中的运用
#define MaxSize 10
#include<iostream>
using namespace std;
typedef struct StackNode {
	char data;
	StackNode * next;
} StackNode,*SqStack;

void InitSqStack(SqStack &S) {
	S=NULL;
}

bool Push(SqStack &S,char c) {
	StackNode *p=new StackNode;
	p->data=c;
	p->next=S;
	S=p;
	return true;
}

bool Pop(SqStack &S,char &c) {
	if(S==NULL) {
		return false;
	}
	StackNode *p=S;
	c=p->data;
	S=p->next;
	delete p;
	return true;
}

bool StackEmpty(SqStack S) {
	if(S==NULL) {
		return true;
	}
	return false;
}

void func_print(SqStack S) {
	StackNode *p=S;
	while(p!=NULL) {
		cout<<p->data;
		p=p->next;
	}
}

bool bracketCheck(SqStack S) {
	SqStack S1;
	InitSqStack(S1);
	StackNode *p=S;
	char topChar;
	while(p!=NULL) {
		if(p->data=='('||p->data=='['||p->data=='{') {
			Pop(S,topChar);
			Push(S1,topChar);
			p=S;
		} 
		else {
			if(StackEmpty(S1)) {
				return false;
			}
			Pop(S1,topChar);
			if(topChar=='('&&p->data!=')') {
				return false;
			}
			if(topChar=='['&&p->data!=']') {
				return false;
			}
			if(topChar=='{'&&p->data!='}') {
				return false;
			}
			Pop(S,topChar);
			p=S;
		}
	}
	return StackEmpty(S1);
}




int main() {
	SqStack S;
	InitSqStack(S);
	Push(S,']');
	Push(S,'}');
	Push(S,'{');
	Push(S,'[');
	func_print(S);
	cout<<bracketCheck(S);
	return 0;
}



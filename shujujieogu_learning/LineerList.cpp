//˳���Ķ�̬���� 
#include <iostream>
using namespace std;
#define InitSize 10
typedef struct{
	int *data;  //ָ���һ��Ԫ�ص�ִ�� 
	int Maxsize;	 //���������� 
	int length;		//��ĵ�ǰ���� 
}SeqList;

//��ʼ�� 
void InitList(SeqList &L){
	L.data=new int[InitSize];
	L.length=0;
	L.Maxsize=InitSize;
} 

//������ĳ���  
void IncreaseSize(SeqList &L,int len){
	int *p=L.data;
	L.data=new int[InitSize+len];
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i];
	}
	L.Maxsize=L.Maxsize+len;
	delete []p;
}

//����
bool ListInsert(SeqList &L,int loc,int elem){
	if(L.length>=L.Maxsize){
		return false;
	}
	if(loc<1||loc>L.length+1){
		return false;
	} 
	for(int j=L.length;j>=loc;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[loc-1]=elem;
	L.length++;
	return true;
}

//ɾ��
bool ListDelete(SeqList &L,int loc){
	if(L.length==0){
		return false;
	}
	if(loc<1||loc>L.length){
		return false;
	}
	for(int j=loc-1;j<L.length-1;j++){
		L.data[j]=L.data[j+1];
	}
	L.length--;
	return true;
} 

//����(��λ����)
int GetElem(SeqList &L,int loc){
	if(loc<1||loc>L.length){
		return 0;
	}
	return L.data[loc-1]
} 

//����(��ֵ����),����λ�� 
int GetElem(Seqlist&L,int elem){
	for(int i=0;i<L.length;L++){
		if(elem==L.data[i]){
			return i+1;
		}
	}
	return 0; //û�в��ҵ��򷵻��� 
} 

int main(){
	SeqList L;
	InitList(L);
	IncreaseSize(L,5);
	cout<<L.length;
	ListInsert(L,1,1) ;
	cout<<L.length;
	ListDelete(L,1);
	cout<<L.length;
	return 0;
}

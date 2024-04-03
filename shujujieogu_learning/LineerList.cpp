//顺序表的动态分配 
#include <iostream>
using namespace std;
#define InitSize 10
typedef struct{
	int *data;  //指向第一个元素的执政 
	int Maxsize;	 //表的最大容量 
	int length;		//表的当前长度 
}SeqList;

//初始化 
void InitList(SeqList &L){
	L.data=new int[InitSize];
	L.length=0;
	L.Maxsize=InitSize;
} 

//增长表的长度  
void IncreaseSize(SeqList &L,int len){
	int *p=L.data;
	L.data=new int[InitSize+len];
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i];
	}
	L.Maxsize=L.Maxsize+len;
	delete []p;
}

//插入
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

//删除
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

//查找(按位查找)
int GetElem(SeqList &L,int loc){
	if(loc<1||loc>L.length){
		return 0;
	}
	return L.data[loc-1]
} 

//查找(按值查找),返回位序 
int GetElem(Seqlist&L,int elem){
	for(int i=0;i<L.length;L++){
		if(elem==L.data[i]){
			return i+1;
		}
	}
	return 0; //没有查找到则返回零 
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

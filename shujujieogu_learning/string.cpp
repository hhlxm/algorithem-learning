//��
#include<iostream>
using namespace std;

#define Maxlen 255
typedef struct {
	char ch[Maxlen];//�����λ�ò��档
	int length;
} SString;

//�󳤶�
int StrLength(SString S){
	return S.length;
} 

//���Ӵ�
bool SubString(SString &sub,SString S,int pos,int len) {
	if(pos+len-1>S.length) {
		return false;
	}
	for(int i=pos; i<pos+len; i++) {
		sub.ch[i-pos+1]=S.ch[i];
	}
	sub.length=len;
	return true;

}

//�Ƚ�
int StrCompare(SString S,SString T) {
	for(int i=1; i<=S.length&&i<=T.length; i++) {
		if(S.ch[i]!=T.ch[i]){
			return S.ch[i]-T.ch[i];
		} 
	}
	//ɨ��������е��ַ�����ͬ���򳤶ȳ��Ĵ�����
	return S.length-T.length; 
}

//��λ�ִ�
int Index(SString S,SString T){
	int i=1,n=StrLength(S),m=StrLength(T);
	SString sub;
	while(i<=n-m-1){
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0){
			i++;
		} else{
			return i;
		}
	}
	return 0;
} 

int main() {

	return 0;
}

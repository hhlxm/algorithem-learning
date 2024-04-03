//串
#include<iostream>
using namespace std;

#define Maxlen 255
typedef struct {
	char ch[Maxlen];//第零个位置不存。
	int length;
} SString;

//求长度
int StrLength(SString S){
	return S.length;
} 

//求子串
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

//比较
int StrCompare(SString S,SString T) {
	for(int i=1; i<=S.length&&i<=T.length; i++) {
		if(S.ch[i]!=T.ch[i]){
			return S.ch[i]-T.ch[i];
		} 
	}
	//扫描过的所有的字符都相同，则长度长的串更大
	return S.length-T.length; 
}

//定位字串
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

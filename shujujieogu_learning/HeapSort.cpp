//������

#include<iostream>
using namespace std;

void HeapAdjust(int a[],int root,int length) {
	a[0]=a[root];
	for(int i=root*2; i<=length; i*=2) {
		if(i<length&&a[i]<a[i+1]) {
			i++;
		}
		if(a[i]>a[0]) {
			a[root]=a[i];
			root=i;
		} else {
			break;
		}
	}
	a[root]=a[0];
}

//���������
void BuildMaxHeap(int a[],int length) {
	for(int i=length/2; i>0; i--) { //��������
		HeapAdjust(a,i,length);
	}
}



void Swap(int &a,int &b) {
	int temp;
	temp=a;
	a=b;
	b=temp;
}

//���ڴ���ѽ�������;
void  HeapSort(int a[],int length) {
	BuildMaxHeap(a,length);
	Swap(a[length],a[1]);
	for(int i=length-1; i>1; i--) {
		HeapAdjust(a,1,i); //ֻ��Ҫ��������ĸ����е���
		Swap(a[i],a[1]);
	}
}

int main() {
	int a[6]= {0,3,51,2,4,1};
	HeapSort(a,5);
	for(int i=1; i<=5; i++) {
		cout<<a[i]<<endl;
	}

	return 0;
}

//�鲢����

#include<iostream>
#include <ctime>
using namespace std;
#define length 5

int b[length]; 
void Merge(int a[],int low ,int mid ,int high) {
	int i,j,k;
	
	for(i=low; i<=high; i++) {
		b[i]=a[i];
	}
	for(i=low,j=mid+1,k=i; i<=mid&&j<=high;) {
		if(b[i]<=b[j]) {
			a[k]=b[i++];

		} else {
			a[k]=b[j++];
		}
		k++;
	}
	while(i<=mid) a[k++]=b[i++];
	while(j<=high) a[k++]=b[j++];
}

void MergeSort(int a[],int low,int high) {
	//a��һ����������ֻ��ϸ��Ϊһ��һ�����й鲢 
	if(low<high) {
		int mid=(low+high)/2;
		MergeSort(a,low,mid);//����ϸ����� 
		MergeSort(a,mid+1,high);//ϸ���ұ� 
		Merge(a,low,mid,high);//���ҹ鲢 
	}
	//���low=high�������Ѿ�ϸ�ֳ�һ��һ�����򷵻ؽ��й鲢 

}

int main() {
	int a[length]={1,2,4,2,3}; 
	
    // ���ù鲢������
    MergeSort(a, 0, length - 1);
	for(int i=0;i<length;i++){
		cout<<a[i]<<endl;
	}

	return 0;
}

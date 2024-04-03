//归并排序

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
	//a不一定有序，所以只能细分为一个一个进行归并 
	if(low<high) {
		int mid=(low+high)/2;
		MergeSort(a,low,mid);//用来细分左边 
		MergeSort(a,mid+1,high);//细分右边 
		Merge(a,low,mid,high);//左右归并 
	}
	//如果low=high，代表已经细分成一个一个，则返回进行归并 

}

int main() {
	int a[length]={1,2,4,2,3}; 
	
    // 调用归并排序函数
    MergeSort(a, 0, length - 1);
	for(int i=0;i<length;i++){
		cout<<a[i]<<endl;
	}

	return 0;
}

//插入排序

#include<iostream>
using namespace std;

//my own
void Insert_sort(int a[],int n) {
	int i=0;
	int j=1;
	int current=0;
	while(j<n) {
		if(a[i+1]<a[i]) {
			for(; i>=0&&a[i+1]<a[i]; i--) {
				current=a[i+1];
				a[i+1]=a[i];
				a[i]=current;
			}
		}

		j++;
		i=j-1;
	}
}

//add sentry to simplify Insert sort algorithem.However,it tends to make a mistake to put the size of array as 'n'
//what's more ,in this algorithem, we don't need to 'exchange'
void Insert_sort1(int a[],int n) {
	int i,j;
	for(i=2; i<=n; i++) {
		if(a[i]<a[i-1]) {
			a[0]=a[i];
			//we don't need to judge if j>=0
			for(j=i-1; a[0]<a[j]; j--) {
				a[j+1]=a[j];
			}
			a[j+1]=a[0];
		}
	}

}

int Binary_Search(int a[],int length,int x) {
	int low=1;
	int high=length;
	int mid=(low+high)/2;
//	while(low<=high) {
//		if(x<a[mid]) {
//			high=mid-1;
//		} else if(x>a[mid]) {
//			low=mid+1;
//		} else {
//			return mid+1;//keep stability
//		}
//		mid=(low+high)/2;
//	}
	while(low<=high){
		if(x<a[mid]) high=mid-1;
		else low=mid+1;
		mid=(low+high)/2; 
	}
	return low;

}
//使用折半查找，because the numbers before the x are sorted 
void Insert_sort2(int a[],int length) {
	int i,j,x;
	for(i=2; i<=length; i++) {
		if(a[i]<a[i-1]) {
			a[0]=a[i];
			j=Binary_Search(a,i-1,a[0]);
			for(x=i;x>j;x--){
				a[x]=a[x-1];
			}
			a[x]=a[0];
		}
	}
}


int main() {
	int a[6]= {0,1,3,0,6,3};
	int n=5;
	Insert_sort2(a,n);
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<endl;
	}
	return 0;
}

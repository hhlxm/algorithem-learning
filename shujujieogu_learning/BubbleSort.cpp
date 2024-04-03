//ц╟ещеепР

#include<iostream>
using namespace std;

void Swap(int &a,int &b) {
	int temp=a;
	a=b;
	b=temp;
}

void BubbleSort(int a[],int length) {
	int i,j;
	bool flag=false;
	for(i=0; i<length-1; i++) {
		for(j=length-1; j>i; j--) {
			if(a[j]<a[j-1]) {
				Swap(a[j],a[j-1]);
				flag=true;
			}
		}
		if(flag==false) {
			return;
		}
	}
}

void BubbleSort1(int a[],int length){
	int i,j;
	bool flag;
	for(i=length-1;i>0;i--){
		for(j=0;j<i;j++){
			if(a[j]>a[j+1]){
				Swap(a[j],a[j+1]);
				flag=true;
			}
		}
		if(flag==false){
			return ;
		}
	}
	
}



int main() {
	int a[6]={1,2,9,0,4,5};
	BubbleSort1(a,6);
	for(int i=0;i<6;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}

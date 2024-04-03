//Ï£¶ûÅÅÐò

#include<iostream>
using namespace std;

void ShellSort(int a[],int length) {
	int i,d,j;
	for(d=length/2; d>=1; d=d/2) {
		for(i=1+d; i<=length; i++) {
			if(a[i]<a[i-d]) {
				a[0]=a[i];
				for(j=i-d; a[j]>a[0]&&j>0; j-=d) {
					a[j+d]=a[j];
				}
				a[j+d]=a[0];
			}
		}
	}



}



int main() {
	int a[9]={0,1,2,3,5,3,9,5,3};
	ShellSort(a,8);
	for(int i=1;i<=8;i++){
		cout<<a[i]<<endl;
	}

	return 0;
}

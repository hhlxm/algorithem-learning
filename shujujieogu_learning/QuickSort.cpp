//©ЛкыеепР

#include<iostream>
using namespace std;




int Partition(int a[],int low,int high) {
	int pivot=a[low];
	while(low<high) {

		while(a[high]>=pivot&&low<high) {
			high--;
		}
		a[low]=a[high];

		while(a[low]<=pivot&&low<high) {
			low++;
		}
		a[high]=a[low];

	}
	a[low]=pivot;
	return low; 
}

void QuickSort(int a[],int low ,int high) {
	if(low<high) {
		int pivotpos=Partition(a,low,high);
		QuickSort(a,low,pivotpos-1);//left
		QuickSort(a,pivotpos+1,high);//right
	}

}

int main() {
	int a[5]={1,2,4,51,2};
	QuickSort(a,0,4);
	for(int i=0;i<5;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}

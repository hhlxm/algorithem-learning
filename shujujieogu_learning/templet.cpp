#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f
#include<vector>
using namespace std;

void min_search(vector<vector<int> >a,int m,int n,int i,int &b) {
	int elem[m];
	int min=INF;
	int l;
	b=0;
	
	for(int j=0;j<m;j++){
		elem[j]=0;
	}
	
	for(int j=0; j<m; j++) {
		if(j==i){
			elem[j]=INF;
			continue;
		}
		for(l=0;l<n;l++)
		elem[j]+=a[j][l]-a[i][l];
	}

	for(int j=0; j<m; j++) {
		if(elem[j]<min){
			for( l=0;l<n;l++){
				if(a[j][l]<=a[i][l]){
					break;
				}
			}
			if(l==n){
				min=elem[j];
				b=j+1;
			} 
		}
	}
	



}



void  Lsearch(vector<vector<int> >a,int m,int n) {
	int b[m];
	for(int j=0; j<m; j++) {
		b[j]=0;
	}
	for(int i=0; i<m; i++) {
		min_search(a,m,n,i,b[i]);
		cout<<b[i]<<endl;
	}


}

signed main() {
	vector<vector<int> >a;
	int m,n;
	cin>>m>>n;
	a.resize(m);
	for(int i=0;i<m;i++){
		a[i].resize(n);
	} 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Lsearch(a,m,n);
	return 0;
}


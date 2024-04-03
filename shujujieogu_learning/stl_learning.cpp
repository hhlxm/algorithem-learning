#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> sub(vector<int >&a,vector<int >&b){
    int flag=0;
    vector<int>c;
    for(int i=0;i<a.size();i++){
        flag=a[i]-flag;
        if(i<b.size()){
            flag=flag-b[i];
        }
        c.push_back((flag+10)%10);
        if(flag<0)flag=1;
        else flag=0;
    }
    while(c.size()>1&&c.back()==0){
        c.pop_back();
    }
    return c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    string a,b;
    cin>>a>>b;
    
    vector<int>x,y,z;
    for(int i=a.size()-1;i>=0;i--)x.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)y.push_back(b[i]-'0');
    if(a>=b){
        z=sub(x,y);
        for(int i=z.size()-1;i>=0;i--){
            cout<<z[i];
        }
    }else{
        cout<<'-';
        z=sub(y,x);
        for(int i=z.size()-1;i>=0;i--){
            cout<<z[i];
        }
    }
    
    return 0;
}

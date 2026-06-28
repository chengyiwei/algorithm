#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,C,F[maxn];
struct node{
    int w,c;
    node(int w=0,int c=0):w(w),c(c){}
};

vector<node> a;

int main(){
    freopen("P1776.in","r",stdin);
    cin>>n>>C;
    for(int i=1;i<=n;i++){
        int w,c,m;cin>>w>>c>>m;
        for(int j=1;j<=m;j<<=1){
            a.push_back(node(w*j,c*j));
            m-=j;
        }
        if(m) a.push_back(node(w*m,c*m));
    }
    for(int i=0;i<a.size();i++)
        for(int j=C;j>=a[i].c;j--)
            F[j]=max(F[j],F[j-a[i].c]+a[i].w);
    cout<<F[C]<<endl;
    return 0;
}
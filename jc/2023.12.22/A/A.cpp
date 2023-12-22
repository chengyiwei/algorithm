#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int vis[maxn];
vector<int> p;
int n,m;
int main(){
    freopen("A.in","r",stdin);
    cin>>n>>m;
    for(int i=2;i<=m;i++)
    for(int j=2;i*j<=m;j++)
        vis[i*j]=1;
    for(int i=2;i<=m;i++)
        if(!vis[i]) p.push_back(i);
    while(n--){
        int l,r;
        cin>>l>>r;
        if(l<1||r>m) {printf("Crossing the line\n");continue;}
        int ans=0;
        printf("%d\n",upper_bound(p.begin(),p.end(),r)-lower_bound(p.begin(),p.end(),l));
    }
    return 0;
}
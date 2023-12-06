#include<bits/stdc++.h>
using namespace std;

int n;
struct edge{
    int x,y,w;
    bool operator <(const edge& B)  {return w<B.w;}
};
vector<edge> E;
vector<int> fa;

int getfa(int x){return fa[x]==x?x:fa[x]=getfa(x);}
int Kruskal(){
    int ans=0;
    fa.resize(n);

    for(int i=0;i<n;i++) fa[i]=i;
    sort(E.begin(),E.end());
    int m=E.size();
    for(int i=0;i<m;i++){
        int fx=getfa(E[i].x),fy=getfa(E[i].y);
        if(fx!=fy) {fa[fx]=fy;ans+=E[i].w;}
    }
    return ans;
}
int main(){
    freopen("MST.in","r",stdin);
}
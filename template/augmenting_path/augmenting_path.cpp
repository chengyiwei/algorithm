#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct Edmonds_Karp{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    a[maxn]; //当起点到 i 的可改进量
    p[maxn]; //
}
int main(){
}
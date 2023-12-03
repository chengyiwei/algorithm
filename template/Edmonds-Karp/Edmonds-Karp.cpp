#include<bits/stdc++.h>
using namespace std;
const int maxn=15;

struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cmp(c),flow(f){}
};

struct EdmondsKarp{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];  //起点到 i 的可改进量
    int p[maxn];

    void init(int n){
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void add_e(int from,int to,int cap){
        
    }
};

int main(){}
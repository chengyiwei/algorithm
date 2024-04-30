#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;

vector<int> a;

struct tree{
    int n;
    vector<int> c;
    tree(int n){this->n=n;c.assign(n+1,0);}
    void update(int x,int val){
        while(x<=n){
            c[x]=val;
            for(int i=1;i<lowbit(x);i<<=1)
                c[x]=max(c[x],c[x-i]);
            x+=lowbit(x);
        }
    }
    int query(int L,int R){
        int ans=0;
        while(L<=R){
            ans=max(ans,a[R]);R--;
            while(R-L>=lowbit(R)){
                ans=max(ans,c[R]);
                R-=lowbit(R);
            }
        }
        return ans;
    }
};

int main(){
    freopen("1754.in","r",stdin);
    int n,m;
    while(1){
        if(scanf("%d%d",&n,&m)==EOF)break;
        tree t(n);a.resize(n+1);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            t.update(i,a[i]);
        }
        while(m--){
            char s[5];int A,B;scanf("%s%d%d",s,&A,&B);
            if(s[0]=='Q') printf("%d\n",t.query(A,B));
            else a[A]=B,t.update(A,B);
        }
    }
    return 0;
}
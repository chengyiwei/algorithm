#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct tree{
    int n;
    vector<int> c;
    tree(int n){this->n=n;c.assign(n+1,0);}
    void add_x(int x,int val){
        for(;x<=n;x+=x&-x)c[x]+=val;
    }
    int get(int x){
        int ret=0;
        for(;x;x-=x&-x)ret+=c[x];
        return ret;
    }
};

int main(){
    while(1){
        int n=read();if(!n)break;
        tree t(n);
        for(int i=1;i<=n;i++){
            int l=read(),r=read();
            t.add_x(l,1);t.add_x(r+1,-1);
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",t.get(i),((i==n)?'\n':' '));
        }
    }
}
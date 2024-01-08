#include<bits/stdc++.h>
using namespace std;

struct Seg_Tree{
    int n;
    vector<int> t;
    Seg_Tree(int n){this->n=n;t.resize(n<<2);}

    void push_up(int x){
        t[x]=t[x<<1]+t[x<<1|1];
    }

    void build(int x,int l,int r,vector<int>& a){
        if(l==r) {t[l]=a[l];return ;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid,a);build(x<<1|1,mid+1,r,a);
        push_up(x);
    }

    int query(int x,int l,int r,int ql,int qr){
        if(l<=ql&&qr<=r) return t[x];
        int mid=(l+r)>>1,ret=0;
        if(l<=mid) ret+=query(x<<1,l,mid,ql,qr);
        if(r>mid)  ret+=query(x<<1|1,mid+1,r,ql,qr);
        return ret;
    }
};

int main(){}

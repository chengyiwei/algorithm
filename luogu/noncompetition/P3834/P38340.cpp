#include<bits/stdc++.h>
using namespace std;
struct Node{
    int lson,rson,sum;
    Node(int lson=0,int rson=0,int sum=0) {this->lson=lson;this->rson=rson;this->sum=sum;}
};

struct Segment_Tree{
    int n,cnt;
    vector<Node> t;
    Segment_Tree(int n){this->n=n;t.assign(n<<5,Node());cnt=0;}
    int update(int pre,int l,int r,int pos){
        int now=++cnt; //动态开点
        t[now].lson=t[pre].lson; t[now].rson=t[pre].rson; t[now].sum=t[pre].sum+1; //复制 lson,rson,sum 比原来的多 1
        int mid=(l+r)>>1;
        if(l<r){
            if(pos<=mid) t[now].lson=update(t[pre].lson,l,mid,pos); //继续往左边走
            else t[now].rson=update(t[pre].rson,mid+1,r,pos); //继续往右边走
        }
        return now;
    }
    int query(int u,int v,int l,int r,int k){ //[u,v] 内第 k 小数，相当于同时在两棵树上面走
        if(l==r) return l;// 返回第 k 小的数字的编号
        int now_lson_x=t[t[v].lson].sum-t[t[u].lson].sum; // 两棵线段树相减,得到左边儿子在 [u,v] 的个数
        int mid=(l+r)>>1;
        if(now_lson_x>=k)
            return query(t[u].lson,t[v].lson,l,mid,k); //在左边儿子
        else 
            return query(t[u].rson,t[v].rson,mid+1,r,k-now_lson_x); //在右边儿子
    }
};

int main(){
    freopen("P3834.in","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    vector<int> a(n+1),b(n+1),rt(n+1,0);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);b[i]=a[i];}  //b 为 a 的副本
    sort(b.begin()+1,b.begin()+1+n);
    int num=unique(b.begin()+1,b.begin()+1+n)-(b.begin()+1);
    Segment_Tree T(n);  //这里不能填num，因为每次新建的结点个数时 logn 的一共有 nlogn
    for(int i=1;i<=n;i++){
        int x=lower_bound(b.begin()+1,b.begin()+1+num,a[i])-b.begin();  // x 为离散化后的 a[i] 的值
        rt[i]=T.update(rt[i-1],1,num,x);
    }
    while(m--){
        int L,R,k;scanf("%d%d%d",&L,&R,&k);
        int id=T.query(rt[L-1],rt[R],1,num,k);
        printf("%d\n",b[id]);
    }
    return 0;
}
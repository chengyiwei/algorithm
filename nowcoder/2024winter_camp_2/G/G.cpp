#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
struct Tree{
    int n;
    vector<int> t;
    Tree(int _n){
        this -> n = _n + 1;
        t.assign(n,0);
    }
    void update(int x, int data){
        for(int i = x; i < n; i += i & -i)
            t[i] += data;
    }
    int query(int x){
        int ans = 0;
        for(int i = x; i; i -= i & -i)
            ans += t[i];
        return ans;
    }
};

struct Seg_Tree{ //区间修改，区间最值
    int n;
    vector<int> t, lazy;
    Seg_Tree(int _n){
        this -> n = _n + 1;
        t.assign(n << 2,0);
        lazy.assign(n << 2,0);
    }
    void push_up(int p){
        t[p] = max(t[p << 1],t[p << 1 | 1]);
    }
    void push_down(int p){
        if(lazy[p]){
            t[p << 1] += lazy[p];
            t[p << 1 | 1] += lazy[p];
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            lazy[p] = 0;
        }
    }
    void build(int p,int l,int r,vector<int> &a,vector<int> &s){
        if(l == r) {t[p] = s[l - 1] - a[l]; return;} 
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a, s);
        build(p << 1 | 1, mid + 1, r, a, s);
        push_up(p);
    }
    void update(int p, int L, int R, int l, int r, int data){
        if(l <= L && r >= R){
            t[p] += data;
            lazy[p] += data;
            return;
        }
        push_down(p);
        int mid = (L + R) >> 1;
        if(l <= mid) update(p << 1, L, mid, l, r, data);
        if(r > mid) update(p << 1 | 1, mid + 1, R, l, r, data);
        push_up(p);
    }
    int query(int p,int L, int R,int l, int r){
        if(l <= L && r >= R) return t[p];
        push_down(p);
        int mid = (L + R) >> 1;
        int ans = -INF;
        if(l <= mid) ans = max(ans,query(p << 1, L, mid, l, r));
        if(r > mid) ans = max(ans,query(p << 1 | 1, mid + 1, R, l, r));
        return ans;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n+1),s(n+1,0); Tree Sum(n); Seg_Tree T(n);
    for(int i = 1; i <= n; i++){
        cin >> a[i]; s[i] = s[i-1] + a[i];
        Sum.update(i,a[i]);
    }
    T.build(1,1,n,a,s);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int pos, val; cin >> pos >> val;
            T.update(1,1,n,pos,pos,a[pos] - val);
            if(pos < n)
                T.update(1,1,n,pos + 1,n,val - a[pos]);
            Sum.update(pos,val-a[pos]);
            a[pos] = val;
        }
        else {
            for(int i=1;i<=n;i++)
                cout << a[i] << ' ';
            cout << '\n';
            int l, r; cin >> l >> r;
            int ans = T.query(1,1,n,l+1,r);
            ans -= Sum.query(l - 1);
            cout << ans << '\n';
        }
    }
}

signed main(){
    freopen("G.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
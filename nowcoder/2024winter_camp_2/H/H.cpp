#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
struct node{
    LL sum, rmx, lmn, lans, rans, segans, ans;
    node(){
        rmx = lans = rans = segans = ans = -INF;
        sum = 0; lmn = INF;
    }
}t[maxn << 2];

int n, q;
LL a[maxn];

node merge_node(node x, node y){
    node res;
    res.sum = x.sum + y.sum;
    res.rmx = max(y.rmx, y.sum + x.rmx);
    res.lmn = min(x.lmn, x.sum + y.lmn);
    res.lans = max({x.lans, x.sum + y.lans, x.sum - y.lmn, x.segans - y.lmn});
    res.rans = max({y.rans, x.rans - y.sum, x.rmx - y.sum, x.rmx + y.segans});
    res.segans = max({x.segans - y.sum, x.sum + y.segans, x.sum - y.sum});
    res.ans = max({x.ans, y.ans, x.rmx - y.lmn, x.rans - y.lmn, x.rmx + y.lans});
    return res;
}

void push_up(int x){
    t[x] = merge_node(t[x << 1], t[x << 1 | 1]);
}

void build(int x, int l, int r){
    t[x] = node();
    if(l == r){
        t[x].sum = t[x].rmx = t[x].lmn = a[l];
        t[x].lans = t[x].rans = t[x].segans = t[x].ans = -INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
    push_up(x);
}

void update(int x, int l, int r, int pos, int val){
    if(l == r){
        t[x].sum = t[x].rmx = t[x].lmn = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(x << 1, l, mid, pos, val);
    else update(x << 1 | 1, mid + 1, r, pos, val);
    push_up(x);
}

node query(int x, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return t[x];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(x << 1, l, mid, ql, qr);
    if(ql > mid ) return query(x << 1 | 1, mid + 1, r, ql, qr);
    return merge_node(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr));
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x, v; cin >> x >> v;
            update(1, 1, n, x, v);
        }
        else{
            int ql, qr; cin >> ql >> qr;
            LL ans = query(1, 1, n, ql, qr).ans;
            cout << ans << '\n';
        }
    }
}

int main(){
    freopen("H.in","r",stdin);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
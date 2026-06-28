#include<bits/stdc++.h>
#define IT set<node>::iterator
using namespace std;
typedef long long LL;
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int imax_n = 1e5 + 7;
struct node
{
    int l,r;
    mutable LL v;
    node(int L, int R=-1, LL V=0):l(L), r(R), v(V) {}
    bool operator<(const node& o) const
    {
        return l < o.l;
    }
};
LL pown(LL a, LL b, LL mod)
{
    LL res = 1;
    LL ans = a % mod;
    while (b)
    {
        if (b&1) 
            res = res * ans % mod;
        ans = ans * ans % mod;
        b>>=1;
    }
    return res;
}
set<node> s;
IT split(int pos)
{
    IT it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos) 
        return it;
    --it;
    int L = it->l, R = it->r;
    LL V = it->v;
    s.erase(it);
    s.insert(node(L, pos-1, V));
    return s.insert(node(pos, R, V)).first;
}
void add(int l, int r, LL val)
{
    IT itr = split(r+1),itl = split(l);
    for (; itl != itr; ++itl) 
        itl->v += val;
}
void assign_val(int l, int r, LL val)
{
    IT itr = split(r+1),itl = split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}
LL ranks(int l, int r, int k)
{
    vector<pair<LL, int> > vp;
    IT itr = split(r+1),itl = split(l);
    vp.clear();
    for (; itl != itr; ++itl)
        vp.push_back(pair<LL,int>(itl->v, itl->r - itl->l + 1));
    sort(vp.begin(), vp.end());
    for (vector<pair<LL,int> >::iterator it=vp.begin();it!=vp.end();++it)
    {
        k -= it->second;
        if (k <= 0) 
            return it->first;
    }
}
LL sum(int l, int r, int ex, int mod)
{
    IT itr = split(r+1),itl = split(l);
    LL res = 0;
    for (; itl != itr; ++itl)
        res = (res + (LL)(itl->r - itl->l + 1) * pown(itl->v, LL(ex), LL(mod))) % mod;
    return res;
}
int n, m;
LL seed, vmax;
LL rd()
{
    LL ret = seed;
    seed = (seed * 7 + 13) % MOD7;
    return ret;
}
LL a[imax_n];
int main()
{
    cin>>n>>m>>seed>>vmax;
    for (int i=1; i<=n; ++i)
    {
        a[i] = (rd() % vmax) + 1;
        s.insert(node(i,i,a[i]));
    }
    s.insert(node(n+1, n+1, 0));
    int lines = 0;
    for (int i =1; i <= m; ++i)
    {
        int op = int(rd() % 4) + 1;
        int l = int(rd() % n) + 1;
        int r = int(rd() % n) + 1;
        if (l > r)
            swap(l,r);
        int x, y;
        if (op == 3)
            x = int(rd() % (r-l+1)) + 1;
        else
            x = int(rd() % vmax) +1;
        if (op == 4)
            y = int(rd() % vmax) + 1;
        if (op == 1)
            add(l, r, LL(x));
        else if (op == 2)
            assign_val(l, r, LL(x));
        else if (op == 3)
            cout<<ranks(l,r,x)<<endl;
        else
            cout<<sum(l,r,x,y)<<endl;
    }
    return 0;
}
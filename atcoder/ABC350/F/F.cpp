#include <bits/stdc++.h>
using namespace std;

struct Node {
    int fa, ch[2], tag, siz;
};
vector<Node> t;
int rt;

bool ident (int x, int f) { // 判断 x 是 f 的左儿子还是右儿子
    return t[f].ch[1] == x;
}

void connect (int x, int f, int op) {
    t[f].ch[op] = x;
    t[x].fa = f;
}

void push_up (int x) {
    t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + 1;
}

void push_down (int x) {
    if (t[x].tag) {
        swap (t[x].ch[0], t[x].ch[1]);
        t[t[x].ch[0]].tag ^= 1;
        t[t[x].ch[1]].tag ^= 1;
        t[x].tag = 0;
    }
}

void build (int l, int r, int f) {
    if (l > r) return ;
    int mid = (l + r) >> 1;
    if (mid < f) t[f].ch[0] = mid;
    else t[f].ch[1] = mid;
    t[mid].siz = 1; t[mid].fa = f;
    if (l == r) return ;
    build(l, mid - 1, mid); build(mid + 1, r, mid);
    push_up(mid);
}

void rotate (int x) {
    int f = t[x].fa, g = t[f].fa, k = ident(x, f);
    connect (x, g, ident(f, g));
    connect (t[x].ch[k ^ 1], f, k);
    connect (f, x, k ^ 1);
    push_up(f); push_up(x);
}

void splay (int x, int top) {
    if (!top) rt = x;
    while (t[x].fa != top) {
        int f = t[x].fa, g = t[f].fa;
        if (g != top)
            ident(x, f) ^ ident(f, g) ? rotate(x) : rotate(f);
        rotate(x);
    }
}

void rever (int L, int R) {
    splay(L, 0); splay(R, L);
    t[t[R].ch[0]].tag ^= 1;
}

int find (int x, int k) { // 找到以 x 为根的树中第 k 个节点
    push_down(x);
    int sum = t[t[x].ch[0]].siz + 1;
    if (sum == k) return x;
    if (sum > k) return find(t[x].ch[0], k);
    else return find(t[x].ch[1], k - sum);
}

void inorder (int x, vector<int> & ord) {
    push_down(x);
    if (t[x].ch[0]) inorder(t[x].ch[0], ord);
    if (x >= 2 && x <= t.size() - 2)
        ord.push_back(x - 1);
    if (t[x].ch[1]) inorder(t[x].ch[1], ord);
}

vector<int> c;
void add_x (int x, int v) {
    for (int i = x; i < c.size(); i += i & -i)
        c[i] += v;
}
int query (int x) {
    int res = 0;
    for (int i = x; i; i -= i & -i)
        res += c[i];
    return res;
}

int main() {
    freopen ("F.in", "r", stdin);
    string s; cin >> s; s = " " + s;
    int n = s.size() - 1;
    t.resize(n + 3); c.resize(n + 1);
    rt = (n + 3) / 2; 
    build(1, rt - 1, rt); build(rt + 1, n + 2, rt);

    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') 
            st.push(i);
        else if (s[i] == ')'){
            int l = st.top(), r = i; st.pop();

            add_x(l, 1); add_x(r + 1, -1);

            int L = find (rt, l), R = find(rt, r + 2);
            rever(L, R);
        }
    }
    vector<int> ord;
    inorder(rt, ord);
    for (auto x : ord) {
        if (s[x] == '(' || s[x] == ')') continue;
        int v = query(x);
        if (v & 1) {
            if ('A' <= s[x] && s[x] <= 'Z') 
                s[x] = s[x] - 'A' + 'a';
            else 
                s[x] = s[x] - 'a' + 'A';
        }
        cout << s[x];
    }
    return 0;
}
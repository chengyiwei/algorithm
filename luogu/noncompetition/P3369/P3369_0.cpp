// Treap
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct Node {
    int ch[2], siz, val, rnd;
    Node(int val = 0, int rnd = 0) : val(val), rnd(rnd) {
        ch[0] = ch[1] = 0;
        siz = 1;
    }
};

int brand() {return rand();}

struct Treap {
    vector<Node> t;
    int root, tot;
    Treap(int n) {t.assign(n + 1, Node()); root = tot = 0;}

    void push_up(int x) {
        t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + 1;
    }

    void rotate(int &x, int op) { // 0左旋 1右旋
        int y = t[x].ch[op];
        t[x].ch[op] = t[y].ch[op ^ 1];
        t[y].ch[op ^ 1] = x;
        push_up(x); push_up(y);
        x = y;
    }

    void insert(int &x, int val) {
        if (!x) {
            x = ++tot;
            t[x] = Node(val, brand());
            return ;
        }
        t[x].siz += 1;
        if (val <= t[x].val) {
            insert(t[x].ch[0], val);
            if (t[t[x].ch[0]].rnd > t[x].rnd) rotate(x, 1);
        }
        else {
            insert(t[x].ch[1], val);
            if (t[t[x].ch[1]].rnd > t[x].rnd) rotate(x, 0);
        }
        push_up(x);
    }

    void del(int &x, int val) {
        t[x].siz -= 1;
        if (val == t[x].val) {
            if (t[x].ch[0] == 0 && t[x].ch[1] == 0) { // 如果没有儿子
                x = 0;
                return ;
            }
            if (t[x].ch[0] == 0 || t[x].ch[1] == 0) { // 如果只有一个儿子
                x = t[x].ch[0] + t[x].ch[1];
                return ;
            }
            if (t[t[x].ch[0]].rnd < t[t[x].ch[1]].rnd) {
                rotate(x, 0); 
                del(t[x].ch[1], val);
                return ;
            }
            else {
                rotate(x, 1);
                del(t[x].ch[0], val);
                return ;
            }
        }
        if (val <= t[x].val) del(t[x].ch[0], val);
        else del(t[x].ch[1], val);
        push_up(x);
    }

    int rank(int x, int val) {
        if (x == 0) return 0;
        if (val <= t[x].val) return rank(t[x].ch[0], val);
        else return t[t[x].ch[0]].siz + 1 + rank(t[x].ch[1], val);
    }

    int kth(int x, int k) {
        if (k == t[t[x].ch[0]].siz + 1) return t[x].val;
        if (k <= t[t[x].ch[0]].siz) return kth(t[x].ch[0], k);
        else return kth(t[x].ch[1], k - t[t[x].ch[0]].siz - 1);
    }

    int pre(int x, int val) {
        if (x == 0) return -INF;
        if (val <= t[x].val) return pre(t[x].ch[0], val);
        int tmp = pre(t[x].ch[1], val);
    }
};

int main() {

}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node {
    bool flg;
    LL pre_sum, suf_sum, mid_sum;
};

struct Segment_Tree {
    int n;
    vector<Node> t;
    Segment_Tree (int n) {
        this->n = n;
        t.resize(n << 2);
    }

    void build (int x, int l, int r, vector<char> &s) {
        if (l == r) {
            if (s[l] == 'Y') {
                t[x].flg = 0;
                t[x].pre_sum = 0; t[x].suf_sum = 1; t[x].mid_sum = 0;
            }
            if (s[l] == 'B') {
                t[x].flg = 1;
                t[x].pre_sum = 0; t[x].suf_sum = 1; t[x].mid_sum = 0;
            }
            if (s[l] == 'R') {
                t[x].flg = 0;
                t[x].pre_sum = 1; t[x].suf_sum = 0; t[x].mid_sum = 0;
            }
            return 
        }
    }
}

int main() {
    freopen ("K.in","r",stdin);

}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
const int N = 110; //矩形个数
vector<double> v;
int find(double x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
struct LINE { //垂直于x轴的线段记录.
    double x, y1, y2; int c; //c表示矩形左侧线段还是右侧
    bool operator< (const LINE& t) const { return x < t.x; }
}; vector<LINE> line; //若不用vector, 应开2倍空间


struct node {
    int l, r;
    int cou; //cou的意义是, 当前区间被覆盖几次(不下传)
    double len;
}t[N << 3]; //特别注意, 应该开8倍空间!! 扫描线本身2倍 + 线段树自身4倍 = 8倍;
double getlen(int l, int r) { return v[r + 1] - v[l]; }
void pushup(int x) {
    if (t[x].cou) t[x].len = getlen(t[x].l, t[x].r);
    else if (t[x].l != t[x].r) t[x].len = t[x << 1].len + t[x << 1 | 1].len;
    else t[x].len = 0;
}

void build(int l, int r, int x = 1) {
    t[x] = { l, r, 0, 0 };
    if (l == r) return;
    int mid = l + r >> 1;
    build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
    //不用pushup
}

void modify(int l, int r, int c, int x = 1) {
    if (l <= t[x].l && r >= t[x].r) {
        t[x].cou += c;
        pushup(x); //特别注意, 别忘了修改后pushup!!!
        return;
    }
    int mid = t[x].l + t[x].r >> 1;
    if (l <= mid) modify(l, r, c, x << 1);
    if (r > mid) modify(l, r, c, x << 1 | 1);
    pushup(x);
}
int main()
{
    freopen("1542.in","r",stdin);
    freopen("15420.out","w",stdout);
    int n; int T = 1;
    while (scanf("%d", &n), n) {
        v.clear(); line.clear(); v.push_back(-0x3f3f3f3f);
        rep(i, n) {
            double x1, y1, x2, y2; scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            line.push_back({ x1, y1, y2, 1 });
            line.push_back({ x2, y1, y2, -1 });
            v.push_back(y1), v.push_back(y2); //离散化y
        }
        sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
        build(1, v.size() - 2); //因为是对(y轴的线段)建树. 有v.size()-1个点, 则线段应再-1. 
        
        sort(line.begin(), line.end());
        
        double res = 0, last = 0; //last表示上一个x的位置
        for (auto& op : line) {
            res += (op.x - last) * t[1].len; //当前结果累加为△x * y轴覆盖长度
            last = op.x;
            modify(find(op.y1), find(op.y2) - 1, op.c);
        }
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2f\n\n", res);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6005;

struct point{
    int x,y,id;
    point (int _x = 0,int _y = 0,int _id = -1) : x(_x), y(_y), id(_id) {}
    bool operator < (const point &p){
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
};
point operator - (const point &p1,const point &p2){
    return point(p1.x - p2.x,p1.y - p2.y,p1.id);
}
point operator + (const point &p1,const point &p2){
    return point(p1.x + p2.x,p1.y + p2.y,p1.id);
}

ll dot(point p1,point p2){
    return 1ll * p1.x * p2.x + 1ll * p1.y * p2.y;
}

ll det(point p1,point p2){
    return 1ll * p1.x * p2.y - 1ll * p2.x * p1.y;
}

int stk[N],tp = 0;
void convex_hull(point *ps,int n,point *ret,int &rtc){
    sort(ps + 1,ps + 1 + n);
    tp = 0; rtc = 0;
    stk[++ tp] = 1;
    for(int i = 2;i <= n;i ++){
        while(tp > 1 && det(ps[stk[tp]] - ps[stk[tp - 1]],ps[i] - ps[stk[tp]]) <= 0) tp --;
        stk[++ tp] = i;
    }
    for(int i = 1;i < tp;i ++) ret[++ rtc] = ps[stk[i]];
    tp = 0;
    stk[++ tp] = n;
    for(int i = n - 1;i >= 1;i --){
        while(tp > 1 && det(ps[stk[tp]] - ps[stk[tp - 1]],ps[i] - ps[stk[tp]]) <= 0) tp --;
        stk[++ tp] = i;
    }
    for(int i = 1;i < tp;i ++) ret[++ rtc] = ps[stk[i]];
    ret[0] = ret[rtc];
}

int get_area(int x,int y){
    if(x > 0 && y >= 0) return 1;
    if(x <= 0 && y > 0) return 2;
    if(x < 0 && y <= 0) return 3;
    if(x >= 0 && y < 0) return 4;
    return 0;
}

bool cmp(point p1,point p2){
    if(get_area(p1.x,p1.y) != get_area(p2.x,p2.y)) return get_area(p1.x,p1.y) < get_area(p2.x,p2.y);
    if(det(p1,p2) == 0) return dot(p1,p1) < dot(p2,p2);
    return det(p1,p2) > 0;
}

int n,rc;
point p[N],q[N],r[N];
int vis[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> p[i].x >> p[i].y; p[i].id = i;
        q[i] = p[i];
    }
    convex_hull(p,n,r,rc);
    for(int i = 1;i <= rc;i ++) vis[r[i].id] = 1;
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        if(vis[q[i].id]) continue;
        for(int j = 1;j <= n;j ++) p[j] = q[j] - q[i];
        sort(p + 1,p + 1 + n,cmp);
        // cout << q[i].x << ',' << q[i].y << " : "; for(int j = 1;j <= n;j ++) cout << p[j].x << ',' << p[j].y << ' '; cout << endl;
        for(int j = 2;j < n;j ++){
            if(vis[p[j].id] && vis[p[j + 1].id]) ans ++;
        }
        if(n > 2 && vis[p[2].id] && vis[p[n].id]) ans ++;
    }
    cout << ans + 1 << '\n';
}

int main(){
    freopen ("M.in", "r", stdin);
    freopen ("M0.out", "w", stdout);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
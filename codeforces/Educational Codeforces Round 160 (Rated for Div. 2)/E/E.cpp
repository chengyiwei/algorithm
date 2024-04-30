#include<iostream>
#include<cstring>
#include<vector>
#include<limits>
using namespace std;
using LL = long long;
const int maxn = 1e4 + 5, maxm = 1e6 + 5;
template<typename cost_t>
struct MinCostMaxFlow{

    const cost_t INF = numeric_limits<cost_t>::max() / 2;
    int h[maxn], e[maxm], ne[maxm], idx;
    cost_t f[maxm], w[maxm], d[maxn], incf[maxn];
    int q[maxn], pre[maxn];
    bool vis[maxn];
    int V, S, T;

    void init(int v, int s, int t){
        for(int i = 0; i <= v; i++) h[i] = -1;
        idx = 0;
        V = v, S = s, T = t;
    }

    void add(int a, int b, cost_t c, cost_t d){
        e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
        e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
    }

    bool spfa(){
        int hh = 0, tt = 0;
        for(int i = 0; i <= V; i++){
            d[i] = INF;
            incf[i] = 0;
            vis[i] = 0;
        }
        q[tt++] = S, d[S] = 0, incf[S] = INF;
        while(hh != tt){
            int t = q[hh++];
            if (hh == maxn) hh = 0;
            vis[t] = 0;
            for(int i = h[t]; ~i; i = ne[i]){
                int j = e[i];
                if (f[i] && d[j] > d[t] + w[i]){
                    d[j] = d[t] + w[i];
                    incf[j] = min(incf[t], f[i]);
                    pre[j] = i;
                    if (!vis[j]){
                        vis[j] = 1;
                        q[tt++] = j;
                        if (tt == maxn) tt = 0;
                    }
                }
            }
        }
        return incf[T] > 0;
    }

    pair<cost_t, cost_t> EK(){
        cost_t flow = 0, cost = 0;
        while(spfa()){
            cost_t t = incf[T];
            flow += t, cost += d[T] * t;
            for(int i = T; i != S; i = e[pre[i] ^ 1]){
                f[pre[i]] -= t, f[pre[i] ^ 1] += t;
            }
        }
        return {flow, cost};
    }
};
MinCostMaxFlow<int> flow;

int main(){
    freopen("E.in", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > c(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }
    int sum1 = 0, sum2 = 0;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i], sum1 += a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i], sum2 += b[i];
    if (sum1 != sum2){
        cout << -1 << '\n';
        return 0;
    }
    int s = 0, t = n + m + 1;
    flow.init(n + m + 1, s, t);
    for(int i = 1; i <= n; i++){
        flow.add(s, i, a[i], 0);
    }
    for(int i = 1; i <= m; i++){
        flow.add(i + n, t, b[i], 0);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (c[i][j] == 0){
                flow.add(i, j + n, 1, 1);
            }
            else{
                ans += 1;
                flow.add(i, j + n, 1, -1);
            }
        }
    }
    auto [f, cost] = flow.EK();
    if (f != sum1) cout << -1 << '\n';
    else cout << ans + cost << '\n';
    return 0;
}
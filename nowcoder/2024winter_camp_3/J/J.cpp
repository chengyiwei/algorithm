#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

vector<int> M[maxn],W[maxn];
int du_m[maxn],du_w[maxn];

int main(){
    freopen("J.in", "r", stdin);
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++){
        int x, y; scanf("%d%d", &x, &y);
        du_m[x]++, du_w[y]++;
        M[x].push_back(y); W[y].push_back(x);
    }
    double ans_m = 0, ans_w = 0;
    for (int i = 1; i <= n; i++){
        double q = 1;
        for(auto j : M[i])
            q *= (1 - 1.0 / du_w[j]);
        ans_m += 1 - q;
    }

    for (int i = 1; i <= m; i++){
        double q = 1;
        for(auto j : W[i])
            q *= (1 - 1.0 / du_m[j]);
        ans_w += 1 - q;
    }
    printf("float\n%.8f %.8f\n", ans_m, ans_w);
    return 0;
}
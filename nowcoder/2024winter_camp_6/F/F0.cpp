#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

vector<int> prime;
void Prime(){
    vector<int> Mark(maxn, 0);
    for(int i = 2; i < maxn; i++){  
        if(Mark[i] == 0) prime.push_back(i);
        for(int j = 0; j < prime.size() && prime[j] * i < maxn; j++){  
            Mark[i * prime[j]] = 1;  
            if(i % prime[j] == 0) break;  
        }  
    } 
}

int a[maxn], n;
int fa[maxn],cnt[maxn];

int getfa(int x) {
    if (x == 0) return 0;
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}

void clear() {
    for (int i = 1; i <= n ; i ++) fa[a[i]] = 0, cnt[a[i]] = 0;
}

void solve() {
    scanf("%d", &n);
    int max_a = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        max_a = max(max_a, a[i]);
        fa[a[i]] = a[i];
    }
    for (auto &x : prime) {
        int ffa = 0;
        for (int j = x; j <= max_a; j += x) {
            if (fa[j] == 0) continue;
            if (ffa == 0) ffa = getfa(j);
            else {
                int fx = getfa(j);
                if (fx != ffa) 
                    fa[fx] = ffa;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt[getfa(a[i])]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[getfa(a[i])] == n) {
            printf("-1 -1\n");
            clear();
            return ;
        }
        else if (cnt[getfa(a[i])] > 0) {
            printf("%d %d\n", cnt[getfa(a[i])], n - cnt[getfa(a[i])]);
            vector<int> ans1, ans2;
            for (int j = 1; j <= n; j++) {
                if (getfa(a[j]) == getfa(a[i]))
                    ans1.push_back(a[j]);
                else
                    ans2.push_back(a[j]);
            }
            for (auto &x : ans1) printf("%d ", x); printf("\n");
            for (auto &x : ans2) printf("%d ", x); printf("\n");
            clear();
            return ;
        }
    }
    printf("-1 -1\n");
    clear();
    return ;
}

int main() {
    freopen("F.in", "r", stdin);
    freopen("F0.out", "w", stdout);
    Prime();
    // printf("%d\n", prime.size());
    int t; scanf("%d", &t);
    while (t--) solve();
    // printf("%.2lf",clock()/1000.0);
    return 0;
}
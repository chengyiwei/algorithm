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

vector<int> a,fa;

int getfa(int x) {
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}

void solve() {
    int n; scanf("%d", &n);
    a.resize(n + 1); fa.resize(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), fa[i] = i;
    sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            int fx = getfa(i), fy = getfa(i - 1);
            if (fx != fy) fa[fx] = fy;
        }
    }

    for (auto &x : prime) {
        int ffa = 0;
        for (int i = 1; i <= n; i++) if(a[i] >= x && a[i] % x == 0) {
            if (ffa == 0) ffa = getfa(i);
            else {
                int fx = getfa(i);
                if (fx != ffa) 
                    fa[fx] = ffa;
            }
        }
    }

    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) cnt[getfa(i)]++;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == n) {
            printf("-1 -1\n");
            return ;
        }
        else if (cnt[i] > 0) {
            printf("%d %d\n", cnt[i], n - cnt[i]);
            vector<int> ans1, ans2;
            for (int j = 1; j <= n; j++) {
                if (getfa(j) == i)
                    ans1.push_back(a[j]);
                else
                    ans2.push_back(a[j]);
            }
            for (auto &x : ans1) printf("%d ", x); puts("");
            for (auto &x : ans2) printf("%d ", x); puts("");
            return ;
        }
    }
}

int main() {
    freopen("F.in", "r", stdin);
    freopen("F.out", "w", stdout);
    Prime();
    // printf("%d\n", prime.size());
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}
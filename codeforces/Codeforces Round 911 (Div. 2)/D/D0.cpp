#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;
const int maxn = 1e5 + 5;
vector<int> factor[maxn];

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    for(int i = 1; i < maxn; i++){
        for(int j = i; j < maxn; j += i){
            factor[j].push_back(i);
        }
    }

    const int N = 1e5;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        vector<int> cnt(N + 1);
        LL pre = 0;
        LL ans = 0;
        vector<LL> f(N + 1);
        for(int i = 0; i < n; i++){
            int x = a[i];
            ans += pre;
            for(int k = factor[x].size() - 1; k >= 0; k--){
                int t = factor[x][k];
                f[t] += cnt[t];
                pre += t * f[t];
                for(auto tt : factor[t]){
                    f[tt] -= f[t];
                }
            }
            for(auto t : factor[x]){
                cnt[t] += 1;
                f[t] = 0;
            }
        }
        cout << ans << '\n';
    }

}
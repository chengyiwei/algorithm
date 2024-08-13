#include<bits/stdc++.h>
using namespace std;

void check(int x,set<int>& st){
    if (x >= 2 && x % 2 == 0)
        st.insert(x);
    int sq = sqrt(x);
    for (int i = 2; i <= sq ; i += 2){
        if (x % i == 0){
            st.insert(i);
            if ( x / i % 2 == 0)
                st.insert(x / i);
        }
    }
}

void solve(){
    int n, p; cin >> n >> p;
    set<int> st;
    for (int k = max(p, 2); k <= n; k ++){
        int m = 2 * k - 2;
        if(n % m == (p % m) || n % m == (m - p + 2) % m)
            st.insert(m);
    }
    cout << st.size() << '\n';
    for (auto x : st)
        cout << x << ' ';
    cout << '\n';
}

int main(){
    freopen("C.in", "r", stdin);
    freopen("C0.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
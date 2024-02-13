#include<bits/stdc++.h>
using namespace std;

void check(int x,set<int>& st){
    if (x >= 2 && x % 2 == 0)
        st.insert(x);
    int sq = sqrt(x);
    for (int i = 2; i <= sq ; i ++){
        if (x % i == 0){
            if  (i % 2 == 0)
                st.insert(i);
            if ( x / i % 2 == 0)
                st.insert(x / i);
        }
    }
}

void solve(){
    int n, p; cin >> n >> p;
    set<int> st;
    check(n - p, st);
    check(n + p - 2, st);
    for (auto it = st.begin(); it != st.end();) {
        if (*it < 2 * p - 2)
            it = st.erase(it);
        else
            ++it;
    }
    cout << st.size() << '\n';
    for (auto x : st)
        cout << x << ' ';
    cout << '\n';
}

int main(){
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
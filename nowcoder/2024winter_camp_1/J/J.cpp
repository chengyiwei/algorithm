#include<bits/stdc++.h>
using namespace std;

int n, x, y;
vector<int> a;

bool check(int d){
    int lst = y;
    set<int> S;
    if(abs(x - y) <= d)
        S.insert(x);
    for(auto x : a){
        if(!S.empty() && abs(x - lst) <= d)
            S.insert(lst);
        while(!S.empty() && *S.begin() < x - d)
            S.erase(S.begin());
        while(!S.empty() && *S.rbegin() > x + d)
            S.erase(*S.rbegin());
        lst = x;
    }
    return !S.empty();
}

int main(){
    freopen("J.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y; a.assign(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    int L = 0, R = 1e9;
    while(L <= R){
        int mid = (L + R) >> 1;
        if(check(mid))
            R = mid - 1;
        else 
            L = mid + 1;
    }
    cout<< L << '\n';
    return 0;
}
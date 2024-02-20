#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxx =a[0],  minx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxx) maxx = a[i];
        if (a[i] < minx) minx = a[i];
    }
    cout << maxx - minx << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}
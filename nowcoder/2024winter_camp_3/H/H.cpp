#include<bits/stdc++.h>
using namespace std;

int f[13][3] = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1},{1,2,2},{2,1,2},{2,2,1},{2,1,1},{1,2,1},{1,1,2},{1,1,1}};

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), z(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> z[i];
    int ans = 0;
    for (int k = 0; k < 13; k++){
        int flg = 1;
        for (int i = 1; i<= n; i++){
            int x = f[k][a[i] - 1], y = f[k][b[i] - 1], c = z[i];
            if(x < y && c == 1) {flg = 0; break;}
            if(x > y && c == 0) {flg = 0; break;}
            if(x == y && c == 1) {flg = 0; break;}
        }
        ans |= flg;
    }
    cout << (ans ? "Yes" : "No") << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
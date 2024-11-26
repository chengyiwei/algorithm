#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n;
string a, b;
void AC(){
    cin >> n >> a >> b;
    string tmp(n, '#');
    if(a == tmp && b == tmp){
        cout << "Yes" << "\n";
        for(int i = 1; i <= 7; i ++){
            cout << tmp << "\n";
        }
        return;
    }
    a = " " + a;
    b = " " + b;
    ll last = 1;
    vector<string> ans;
    string p(n, '.');
    p = " " + p;
    for(int i = 1; i <= n; i ++){
        if(a[i - 1] == '.' && a[i] == '#'){
            for(int j = last; j < i; j ++){
                p[j] = '#';
            }
        }
        if(a[i - 1] == '#' && a[i] == '.') last = i;
    }
    if(a[n] == '.'){
        for(int i = last; i <= n; i ++){
            p[i] = '#';
        }
    }
    ll idx1 = 0, idx2 = 0;
    for(int i = 1; i <= n; i ++){
        if(p[i - 1] == '.' && p[i] == '#'){
            idx1 = i - 1;
            break;
        }
        if(p[i - 1] == '#' && p[i] == '.'){
            idx1 = i;
        }
    }
    ans.push_back(a);
    ans.push_back(p);
    p = " " + string(n, '.');
    last = 1;
    for(int i = 1; i <= n; i ++){
        if(b[i - 1] == '.' && b[i] == '#'){
            for(int j = last; j < i; j ++){
                p[j] = '#';
            }
        }
        if(b[i - 1] == '#' && b[i] == '.') last = i;
    }
    if(b[n] == '.'){
        for(int i = last; i <= n; i ++){
            p[i] = '#';
        }
    }
    for(int i = 1; i <= n; i ++){
        if(p[i - 1] == '.' && p[i] == '#'){
            idx2 = i - 1;
            break;
        }
        if(p[i - 1] == '#' && p[i] == '.'){
            idx2 = i;
        }
    }
    string o = " " + string(n, '.');
    string qwq = o;
    qwq[idx1] = '#';
    ans.push_back(qwq);
    ll l = min(idx1, idx2);
    ll r = max(idx1, idx2);
    qwq = o;
    if(l == r || l + 1 == r) qwq[l] = '#';
    for(int i = l + 1; i < r; i ++){
        qwq[i] = '#';
    }
    ans.push_back(qwq);
    qwq = o;
    qwq[idx2] = '#';
    ans.push_back(qwq);
    ans.push_back(p);
    ans.push_back(b);
    if(idx1 && idx2){
        cout << "Yes\n";
        for(int i = 0; i < 7; i ++){
            for(int j = 1; j <= n; j ++){
                cout << ans[i][j];
            }
            cout << "\n";
        }
        return;
    }
    string tmpp = " " + string(n, '.');
    if(a == tmpp || b == tmpp){
        cout << "Yes\n";
        for(int i = 0; i < 7; i ++){
            for(int j = 1; j <= n; j ++){
                cout << ans[i][j];
            }
            cout << "\n";
        }
        return;
    }
    cout << "No\n";
}
int main(){
    // freopen("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}
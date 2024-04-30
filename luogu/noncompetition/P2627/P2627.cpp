#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;

int n, k;
LL s[maxn], f[maxn], ds[maxn];

struct node{
    int id; LL val;
    node(int id, LL val):id(id), val(val){}
};

deque<node> q;
// f[i] = max{f[j]-s[j + 1]} + s[i] (i-k <= j <= i)
int main(){
    freopen ("P2627.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> s[i]; s[i] = s[i-1] +  s[i];
    }
    q.push_back(node(0, 0));
    for (int i = 1; i <= n; i++){

        while (!q.empty() && q.front().id < i - k) q.pop_front();

        f[i] = f[i - 1]; //不选
        f[i] = max(f[i], q.front().val + s[i]); //选
        node cur(i, f[i - 1] - s[i]);

        while (!q.empty() && q.back().val <= cur.val) q.pop_back();
        q.push_back(cur);
    }
    cout << f[n] << endl;
    return 0;
}
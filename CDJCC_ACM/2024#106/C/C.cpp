#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
int fa[maxn], cnt = 0;
map<string, int> mp;
string name[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    // freopen ("C.in", "r", stdin);
    for (int i = 1; i < maxn; i++) fa[i] = i;
    string s, father, son;
    while (true) {
        cin >> s;
        if (s.front() == '$') break;
        if (s.front() == '#') {
            father = s.substr(1);
            if (!mp.count(father)) mp[father] = ++cnt, name[cnt] = father;
        }
        if (s.front() == '+') {
            son = s.substr(1);
            if (!mp.count(son)) mp[son] = ++cnt, name[cnt] = son;
            fa[find(mp[son])] = find(mp[father]);
        }
        if (s.front() == '?') {
            son; son = s.substr(1);
            father = name[find(mp[son])];
            cout << son << " " << father << '\n';
        }
    }
    return 0;
}
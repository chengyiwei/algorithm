#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 2e5 +  5;

struct Info {
    map<int, int> a, b;
    int a0, b0;
    int num_a, num_b;
    Info() {a0 = 0, b0 = 0; a.clear(), b.clear(); num_a = num_b = 0;}
}info[MAXN];

int n;
int a[MAXN], b[MAXN];
vector<int> mp[MAXN];

void check (map<int, int>& x,  map<int, int>& y, int& num_a, int& num_b) {
    int flg = 0;
    if (x.size() < y.size()) {swap(x, y); flg = 1;swap(num_a, num_b);}
    auto it = y.begin();
    while (it != y.end()) {
        auto _ = it->first;
        if (x.count(_)) {
            int m = min(x[_], it->second);
            x[_] -= m; it->second -= m;
            if (x[_] == 0) x.erase(_);
            ++it;
            if (y[_] == 0) y.erase(_);
            num_a -= m; num_b -= m;
        }
        else { ++it; }
    }
    if (flg) {swap(x, y); swap(num_a, num_b);}
};

void  merge (map<int, int>& x,  map<int, int>& y, int& num_a, int& num_b) {
    if (x.size() < y.size()) {swap(x, y); swap(num_a, num_b);}
    for (auto y_ : y) {
        x[y_.first] += y_.second;
    }
    num_a += num_b;
};

int s[MAXN];

void dfs (int u, int f) {
    if (a[u] == 0) info[u].a0 += 1;
    else if (a[u] != b[u]) info[u].a[a[u]] += 1, info[u].num_a += 1;

    if (b[u] == 0) info[u].b0 += 1;
    else if (b[u] != a[u]) info[u].b[b[u]] += 1, info[u].num_b += 1;

    for (auto v : mp[u]) {
        if (v == f) continue;
        dfs(v, u);
        check(info[u].a, info[v].b, info[u].num_a, info[v].num_b);
        check(info[u].b, info[v].a, info[u].num_b, info[v].num_a);

        merge(info[u].a, info[v].a,info[u].num_a, info[v].num_a);
        merge(info[u].b, info[v].b,info[u].num_b, info[v].num_b);
        
        info[u].a0 += info[v].a0;
        info[u].b0 += info[v].b0;
    }

    // cout << u << " " << info[u].num_a << " " << info[u].b0 << " " << info[u].num_b << " " << info[u].a0 << "\n";
    if (info[u].num_a <= info[u].b0 and info[u].num_b <= info[u].a0) s[u] = 1;
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) mp[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v); mp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        info[i] = Info();
        s[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << &info[i].a << ' ';
    }
    cout << '\n';
    
    dfs(1, 0);
docker run -d -it --name dj-mariadb -e MYSQL_ROOT_PASSWORD=ROOT998244353 -e MYSQL_USER=domjudge -e CONTAINER_TIMEZONE=Asia/Shanghai -e MYSQL_PASSWORD=DOM998244353 -e MYSQL_DATABASE=domjudge -p 13306:3306 mariadb --max-connections=1000 --max-allowed-packet=102400000 --innodb-log-file-size=202400000
docker run -d -it --name dj-mariadb -e MYSQL_ROOT_PASSWORD=ROOT998244353 -e MYSQL_USER=domjudge -e CONTAINER_TIMEZONE=Asia/Shanghai -e MYSQL_PASSWORD=DOM998244353 -e MYSQL_DATABASE=domjudge -p 13306:3306 mariadb --max-connections=1000 --max-allowed-packet=102400000 --innodb-log-file-size=202400000

docker run --link dj-mariadb:mariadb -d -it -e MYSQL_HOST=mariadb -e MYSQL_USER=domjudge -e MYSQL_DATABASE=domjudge -e CONTAINER_TIMEZONE=Asia/Shanghai -e MYSQL_PASSWORD=DOM998244353 -e MYSQL_ROOT_PASSWORD=ROOT998244353 -p 80:80 --name domserver domjudge/domserver:latest
docker run --link dj-mariadb:mariadb -d -it -e MYSQL_HOST=mariadb -e MYSQL_USER=domjudge -e MYSQL_DATABASE=domjudge -e CONTAINER_TIMEZONE=Asia/Shanghai -e MYSQL_PASSWORD=DOM998244353 -e MYSQL_ROOT_PASSWORD=ROOT998244353 -p 80:80 --name domserver domjudge/domserver:8.2.3

    for (int i = 1; i <= n; i++) {
        cout << &info[i].a << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++)
        cout << s[i];


    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
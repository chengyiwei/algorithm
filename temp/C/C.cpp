#include <bits/stdc++.h>
using namespace std;

constexpr int M = 2e5 + 5;

vector<int> prime;
bool is_prime[M];
map<int, int> id_prime;

void get_prime() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    for (int i = 2; i < M; i++) {
        if (is_prime[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < M; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < prime.size(); i++) 
        id_prime[prime[i]] = i;
}

int get_sg(vector<int> a) {
    int n = a.size() - 1;
    vector<int> sg(n + 1, 0);

    int max_prime;
    for (int i = 1; i <= n; i++) {
        if (id_prime.find(a[i]) != id_prime.end()) {
            max_prime = max(max_prime, a[i]);
        }
    }

    auto mex = [&](vector<int> &v) {
        set<int> s;
        for (int i : v) s.insert(i);
        for (int i = 0; i < v.size(); i++) {
            if (s.find(i) == s.end()) return i;
        }
        return (int)v.size();
    };

    vector<int> q;

    for (int i = n; i >= 1; i--) {
        if (id_prime.find(a[i]) == id_prime.end()) continue;
        // if (a[i] == max_prime) {sg[i] = 1; continue;}
        q.clear();
        int nxt_prime = prime[id_prime[a[i]] + 1];
        for (int j = i + 1; j <= n; j++) {
            if (a[j] == nxt_prime) q.push_back(sg[j]);
        }
        sg[i] = mex(q);
    }
    for (int i = 1; i <= n; i++) 
        if (a[i] == 2) return sg[i];
    return 0;
}

int main() {
    freopen ("C.in", "r", stdin);
    int n; cin >> n;
    get_prime();
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int sg_a = get_sg(a), sg_b = get_sg(b);
    if ((sg_a ^ sg_b)) cout << "Win\n";
    else cout << "Loss\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	int l, r;
	Node(int l = 0, int r = 0) : l(l), r(r) {}
	bool operator < (const Node b) const {
		return l < b.l;
	}
};

const int MAXN = 4e5 + 5;

void AC() {
	int n, m; cin >> n >> m;
	vector<Node> a(m + 1);
    const int MAXN = 2 * n + 5;
    vector<int> c(MAXN, 0);

    auto update = [&] (int x) {
        for (; x < MAXN; x += x & -x) c[x] += 1;
    };

    auto query = [&] (int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) res += c[x];
        return res;
    };

	vector<int> ans(2 * n + 1, 1);
	for (int i = 1; i <= m; i++) cin >> a[i].l >> a[i].r;
	sort(a.begin() + 1, a.end());
	
    int cnt = 0;
	for (int i = m; i >= 1; i--) {
		int pl = query(a[i].l - 1), pr = query(a[i].r);
		if (pl == pr) {
			ans[a[i].l] = -1;
			update(a[i].l);
            cnt += 1;
		}
	}
	
    for (int i = 1; i <= 2 * n; i++) {
        if (ans[i] == 1 && cnt < n) {
            ans[i] = -1;
            cnt += 1;
        }
    }

	int now = 0;
	for (int i = 1; i <= 2 * n; i++) {
        now += ans[i];
        if (now > 0) {
            cout << -1 << '\n';
            return ;
        }
    }
    if (now != 0) {
        cout << -1 << '\n';
        return ;
    }

	for (int i = 1; i <= 2 * n; i++)
		cout << (ans[i] == -1 ? '(' : ')');
	cout << '\n';
	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int Tex; cin >> Tex;
    while(Tex --) AC();
    return 0;
}
/*
1
2 2
1 2
3 4
*/
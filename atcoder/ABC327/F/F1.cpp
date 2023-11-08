#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, d, w, res;
pair<int, int> a[N];

struct Tree
{
	int l, r, v, add;
}tr[N << 2];

#define ls (u << 1)
#define rs (u << 1 | 1)

void pushup(int u)
{
	tr[u].v = max(tr[ls].v, tr[rs].v);
}

void calc(int u, int x)
{
	tr[u].add += x;
	tr[u].v += x;
}

void pushdown(int u)
{
	calc(ls, tr[u].add);
	calc(rs, tr[u].add);
	tr[u].add = 0;
}

void build(int u, int l, int r)
{
	tr[u] = {l, r, 0, 0};
	if (l != r)
	{
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(u);
	}
}

void modify(int u, int l, int r, int x)
{
	if (tr[u].l >= l && tr[u].r <= r) calc(u, x);
	else
	{
		int mid = tr[u].l + tr[u].r >> 1;
		pushdown(u);
		if (l <= mid) modify(ls, l, r, x);
		if (r > mid) modify(rs, l, r, x);
		pushup(u);
	}
}

int query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
	int mid = tr[u].l + tr[u].r >> 1, res = -2e9;
	if (l <= mid) res = query(ls, l, r);
	if (r > mid) res = max(res, query(rs, l, r));
	return res;
}

int main()
{
    freopen("F.in","r",stdin);
    freopen("F1.out","w",stdout);
	cin >> n >> d >> w;
	
	for (int i = 1; i <= n; ++ i )
		cin >> a[i].first >> a[i].second;
	
	sort(a + 1, a + n + 1);
	
	build(1, 1, N - 1);

	for (int i = 1, j = 1; j <= n; ++ j )
	{
		modify(1, max(1, a[j].second - w + 1), a[j].second, 1);
		
		while (i <= j && a[j].first - a[i].first + 1 > d)
			modify(1, max(1, a[i].second - w + 1), a[i].second, -1),
			++ i;
		
		if (a[j].first - a[i].first + 1 <= d)
			res = max(res, query(1, 1, N - 1));
	}
	
	cout << res;
	return 0;
}
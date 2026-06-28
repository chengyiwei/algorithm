#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define endl '\n'
using db = double;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<>>;
#include "atcoder/convolution.hpp"
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
int n, K, N;
const int D = ((db)sqrt(2e5) / (db)(log(2e5) / log(2)) + 1);
const int maxn = 3e5;
mint fac[maxn + 1], invfac[maxn + 1];
mint binom(int nn, int mm)  //求组合数 C(mm,nn)
{
	if (nn < mm)
		return 0;
	return fac[nn] * invfac[nn - mm] * invfac[mm];
};
void init()
{
	fac[0] = 1;
	for (int i = 1; i <= maxn; ++i)
		fac[i] = fac[i - 1] * i;
	invfac[maxn] = 1 / fac[maxn];
	for (int i = maxn - 1; i >= 0; --i)
		invfac[i] = invfac[i + 1] * (i + 1);
}
void solve1()
{
	vector<mint> f(n + 1);
	mint tot = 1;
	mint inv = 1, invK = mint{K}.inv();
	for (int i = 1; i <= n; ++i)
	{
		tot *= K;
		mint res = 0;
		inv *= invK;
		if (1LL * i * K < 1LL * n)
		{
			f[i] = 0;
			continue;
		}
		for (int j = 0; j <= i; ++j)
		{
			int sgn = (j % 2 == 0) ? 1 : -1;
			if (1LL * n - 1 - 1LL * j * (K) < 0)
				break;
			res += sgn * binom(i, j) * binom(n - 1 - j * (K), i);
		}
		f[i] = (tot - res) * inv;
	}
	for (int i = n; i >= 1; --i)
		f[i] -= f[i - 1];
	for (int i = 1; i <= n; ++i)
		cout << f[i].val() << endl;
}
vector<mint> a, f;
vector<mint> dc(int l, int r, vector<mint> g)
{
	int b = min<int>(g.size(), (r - l - 1) * K + 1); // 只保留最后 (r - l) * K 个
	g.erase(begin(g), begin(g) + g.size() - b);
	if (l + 1 == r)
	{
		a[l] = g.back();
		return f;
	}
	int m = (l + r) / 2;
	auto p = dc(l, m, g);
	g = atcoder::convolution(g, p), g.resize(b);
	auto q = dc(m, r, g);
	auto res = atcoder::convolution(p, q);
	if ((int)res.size() > N) res.resize(N);
	return res;
}
void solve2()
{
	a.resize(n + 1);
	f.resize(K + 1);
	for (int i = 1; i <= K; i++)
		f[i] = mint{K}.inv();
	dc(0, N + 1, vector<mint>(N, 1));
	for (int i = 0; i < n; i++)
		cout << (a[i] - a[i + 1]).val() << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> K;
	N = n;
	init();
	if (K > D)
		solve1();
	else
		solve2();
	return 0;
}
// FFT 非递归实现

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 22;
const double eps = 1e-6, pi = acos(-1);

complex<double> a[MAXN], b[MAXN], c[MAXN];
int R[MAXN];
int n, m;

void change(complex<double> A[], int n) {
    for (int i = 0; i < n; i++)
        R[i] = (R[i >> 1] >> 1) + ((i & 1) ? n >> 1 : 0);
    for (int i = 0; i < n; i++)
        if (i < R[i]) swap(A[i], A[R[i]]); // 只需要换一次
}

void FFT(complex<double> *a, int n, int inv) { // inv 为 1 时为 FFT, inv 为 -1 时为 IFFT
    change(a, n);
    for (int m = 2; m <= n; m <<= 1) { // 枚举块的大小
        complex<double> w1(cos(2 * pi / m), inv * sin(2 * pi / m));
        for (int i = 0; i < n; i += m) { // 枚举块的起点
            complex<double> wk(1, 0);
            for (int j = 0; j < m / 2; j++, wk *= w1)  { // 枚举块内的每个点
                auto x = a[i + j], y = wk * a[i + j + m / 2];
                a[i + j] = x + y; a[i + j + m / 2] = x - y;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) {double x; scanf("%lf", &x); a[i].real(x);}
    for (int i = 0; i <= m; i++) {double x; scanf("%lf", &x); b[i].real(x);}
    int len = 1 << max((int)ceil(log2(n + m)), 1); //由于FFT需要项数为2的整数次方倍，所以多项式的次数len为第一个大于 n+m 的二的正整数次方
    FFT(a, len, 1); FFT(b, len, 1);
    for (int i = 0; i < len; i++) c[i] = a[i] * b[i];
    FFT(c, len, -1);
    for (int i = 0; i <= n + m; i++)
        printf("%.0f ",(c[i].real() / len + eps));
    return 0;
}
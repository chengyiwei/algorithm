#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 22;
const double eps = 1e-6, pi = acos(-1);

complex<double> a[MAXN], b[MAXN], c[MAXN];
int n, m;

void FFT(complex<double> *a, int n, int inv) { // inv 为 1 时为 FFT, inv 为 -1 时为 IFFT
    if (n == 1) return;
    int mid = n >> 1;
    complex<double> A1[mid + 1], A2[mid + 1];
    for (int i = 0; i <= n; i += 2) {
        A1[i >> 1] = a[i];
        A2[i >> 1] = a[i + 1];
    }
    FFT(A1, mid, inv); FFT(A2, mid, inv);
    complex<double> w0(1, 0), wn(cos(2 * pi / n), inv * sin(2 * pi / n));
    for (int i = 0; i < mid; i++, w0 *= wn) {
        a[i] = A1[i] + w0 * A2[i];
        a[i + mid] = A1[i] - w0 * A2[i];
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
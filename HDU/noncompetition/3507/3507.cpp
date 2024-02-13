#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 10;

int n, m;
int f[maxn],sum[maxn];

int X(int x) {return 2 * sum[x];}
int Y(int x) {return f[x] + sum[x] * sum[x];}
// double slope(int x, int y) {return 1.0 * (Y(x) - Y(y)) / (X(x) - X(y));}
int slope_up(int x, int y) {return (Y(x) - Y(y));}
int slope_down(int x, int y) {return (X(x) - X(y));}

int main(){
    freopen ("3507.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF) {
        sum[0] = f[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &sum[i]);
            sum[i] += sum[i - 1];
        }
        deque<int> q; q.push_back(0);
        for (int i = 1; i <= n; i++) {
            while (q.size() > 1 && slope_up(q[1], q[0]) <= sum[i] * slope_down(q[1], q[0])) {
                // printf("pop %d\n", q[0]);
                q.pop_front();
            }
            int j = q.front();
            f[i] = f[j] + m + (sum[i] - sum[j]) * (sum[i] - sum[j]);
            while (q.size() > 1 && slope_up(i, q[q.size() - 1]) * slope_down(q[q.size() - 1], q[q.size() - 2]) <= slope_up(q[q.size() - 1], q[q.size() - 2]) * slope_down(i, q[q.size() - 1])) 
                q.pop_back();
            q.push_back(i);
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
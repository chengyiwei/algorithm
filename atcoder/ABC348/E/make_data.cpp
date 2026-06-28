#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    freopen ("E.in", "w", stdout);
    srand(GetTickCount());
    int N = 100000;
    printf("%d\n", N);
    vector<pair<int, int> > edges;
    for (int i = 2; i <= N; i++) {
        int u = i, v = rand() % (i - 1) + 1;
        edges.push_back({u, v});
    }
    random_shuffle(edges.begin(), edges.end());
    for (auto [u, v] : edges)
        printf("%d %d\n", u, v);
    for (int i = 1; i <= N; i++)
        printf("%d ", rand() % 1000000000 + 1);
    return 0;
}
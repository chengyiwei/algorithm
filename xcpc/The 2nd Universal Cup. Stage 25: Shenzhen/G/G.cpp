#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305, MAXM = 60005;

int N, Q, M, K;

char s[MAXN][MAXM];
bitset<MAXN> diff[26][MAXM];
bitset<MAXN> ans[11];
char sq[MAXM];

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    scanf("%d %d %d %d\n", &N, &Q, &M, &K);
    for (int i = 1; i <= N; i++) 
        scanf("%s", s[i] + 1);
    
    for (char c = 'a'; c <= 'z'; c++)
        for (int j = 1; j <= M; j++) 
            for (int i = 1; i <= N; i++) 
                if (s[i][j] != c)
                    diff[c - 'a'][j][i] = 1;
    
    // for (char c = 'a'; c <= 'z'; c++) {
    //     for (int j = 1; j <= M; j++)
    //         printf("c = %c, j = %d, diff = %d\n", c, j, int(diff[c - 'a'][j].to_ulong()));
    // }
    // printf("\n");

    while (Q--) {
        scanf("%s", sq + 1);
        for (int i = 0; i <= K; i++) ans[i] = 0;
        for (int j = 1; j <= M; j++) {
            // printf("sq[%d] = %c, now = %d\n", j, sq[j], int(now.to_ulong()));
            
            for (int k = K; k >= 1; k--) { 
                ans[k] |= ans[k - 1] & diff[sq[j] - 'a'][j];
                // printf("j = %d, ans[%d] = %d\n", j, k, int(ans[k].to_ulong()));
            }
            ans[0] |= diff[sq[j] - 'a'][j];
        }
        // printf("K = %d, ans[K].count() = %d\n", K, int(ans[K].count()));
        printf("%d\n", N - int(ans[K].count()));
    }
    
    return 0;
}
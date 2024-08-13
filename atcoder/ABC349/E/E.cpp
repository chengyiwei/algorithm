#include <bits/stdc++.h>
using namespace std;
int dp[1 << 18];
bool vis[1 << 18];

int A[9];
int line[8] = {0b111, 0b111000, 0b111000000, 0b1001001, 0b10010010, 0b100100100, 0b100010001, 0b1010100};

int get_bit (int x, int v) {
    return (x >> v) & 1;
}

int f (int now, array<int, 2> state) {
    for (int x : line) {
        if (x == (state[0] & x)) return 0;
        if (x == (state[1] & x)) return 1;
    }
    if ((state[0] | state[1]) == 511) {
        long long v = 0;
        for (int i = 0; i < 9; i++)
            if (get_bit(state[0], i))
                v += A[i];
            else 
                v -= A[i];
        return v < 0;
    }
    if (vis[state[0] | (state[1] << 9)]) return dp[state[0] | (state[1] << 9)];
    vis[state[0] | (state[1] << 9)] = 1;
    dp[state[0] | (state[1] << 9)] = now;
    for (int i = 0; i < 9; i++) {
        if (get_bit(state[0], i) || get_bit(state[1], i)) continue;
        array<int, 2> nxt = state;
        nxt[now] |= 1 << i;
        if (f(now ^ 1, nxt) == now) return now;
    }
    return dp[state[0] | (state[1] << 9)] = now ^ 1;
 
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
int main() {
    for (int i = 0; i < 9; i++) cin >> A[i];
    cout << (!f(0, {0, 0}) ? "Takahashi" : "Aoki") << endl;
    return 0;
}
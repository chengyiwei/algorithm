#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Block {
    int a[4][4];
    void read() {
        for (int i = 0; i <= 3; i++)
            for (int j = 0; j <= 3; j++) {
                char ch; cin >> ch;
                if (ch == '.') a[i][j] = 0;
                else a[i][j] = 1;
            }
    }
    Block rotate() {
        Block res; // 旋转90度
        for (int i = 0; i <= 3; i++)
            for (int j = 0; j <= 3; j++)
                res.a[i][j] = a[3 - j][i];
        return res;
    }
    bool check (int sx, int sy) {
        for (int i = 0; i <= 3; i++)
            for (int j = 0; j <= 3; j++)
                if (a[i][j] == 1 ) {
                    if (sx + i < 0 || sx + i > 3 || sy + j < 0 || sy + j > 3) return false;
                }
        return true;
    }
    Block() { memset(a, 0, sizeof(a));}
};

int main() {
    freopen ("D.in", "r", stdin);
    Block A, B, C;
    A.read(); B.read(); C.read();
    vector<Block> all_A; all_A.push_back(A);
    for (int i = 1; i <= 3; i++) all_A.push_back(all_A.back().rotate());
    vector<Block> all_B; all_B.push_back(B);
    for (int i = 1; i <= 3; i++) all_B.push_back(all_B.back().rotate());
    vector<Block> all_C; all_C.push_back(C);
    for (int i = 1; i <= 3; i++) all_C.push_back(all_C.back().rotate());
    for (auto &A_ : all_A)
        for (auto &B_ : all_B)
            for (auto &C_ : all_C)
                for (int x_A = -3; x_A <= 3; x_A++)
                    for (int y_A = -3; y_A <= 3; y_A++) if (A_.check(x_A, y_A)) 
                        for (int x_B = -3; x_B <= 3; x_B++)
                            for (int y_B = -3; y_B <= 3; y_B++) if (B_.check(x_B, y_B))
                                for (int x_C = -3; x_C <= 3; x_C++)
                                    for (int y_C = -3; y_C <= 3; y_C++) if (C_.check(x_C, y_C)) {

                                        auto OK = [&] () -> bool {
                                            Block cur;
                                            for (int i = 0; i <= 3; i++)
                                                for (int j = 0; j <= 3; j++) if (A_.a[i][j] == 1) {
                                                    cur.a[x_A + i][y_A + j] = A_.a[i][j];
                                                }
                                            for (int i = 0; i <= 3; i++)
                                                for (int j = 0; j <= 3; j++) if (B_.a[i][j] == 1) {
                                                    if (cur.a[x_B + i][y_B + j] == 1) return false;
                                                    cur.a[x_B + i][y_B + j] = B_.a[i][j];
                                                }
                                            for (int i = 0; i <= 3; i++)
                                                for (int j = 0; j <= 3; j++) if (C_.a[i][j] == 1) {
                                                    if (cur.a[x_C + i][y_C + j] == 1) return false;
                                                    cur.a[x_C + i][y_C + j] = C_.a[i][j];
                                                }
                                            int cnt = 0;
                                            for (int i = 0; i <= 3; i++)
                                                for (int j = 0; j <= 3; j++) if (cur.a[i][j] == 1) cnt++;
                                            return cnt == 16;
                                        };

                                        if (OK()) {
                                            cout << "Yes" << endl;
                                            return 0;
                                        }
                                    }
    cout << "No" << endl;
    return 0;
}
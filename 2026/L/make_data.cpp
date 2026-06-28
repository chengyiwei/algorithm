#include <bits/stdc++.h>
using namespace std;

static mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

char rand_char() {
    static const string cs =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()-_=+[]{};:,.<>/?|~";
    return cs[randint(0, (int)cs.size() - 1)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1000000;  // 你也可以改成读入
    string s;
    s.reserve(n);

    // 先随机拼一些小块
    // 每个块有较大概率包含至少一个相邻相同字符
    while ((int)s.size() < n) {
        int type = randint(1, 5);

        if (type == 1) {
            // 形如 xaa y
            char x = rand_char();
            char a = rand_char();
            char y = rand_char();
            s += x;
            if ((int)s.size() < n) s += a;
            if ((int)s.size() < n) s += a;
            if ((int)s.size() < n) s += y;
        } else if (type == 2) {
            // 形如 abb a
            char a = rand_char();
            char b = rand_char();
            s += a;
            if ((int)s.size() < n) s += b;
            if ((int)s.size() < n) s += b;
            if ((int)s.size() < n) s += a;
        } else if (type == 3) {
            // 形如 xaax
            char x = rand_char();
            char a = rand_char();
            s += x;
            if ((int)s.size() < n) s += a;
            if ((int)s.size() < n) s += a;
            if ((int)s.size() < n) s += x;
        } else if (type == 4) {
            // 纯随机 3~6 个字符
            int len = randint(3, 6);
            for (int i = 0; i < len && (int)s.size() < n; ++i) {
                s += rand_char();
            }
        } else {
            // 形如 xyyz
            char x = rand_char();
            char y = rand_char();
            char z = rand_char();
            s += x;
            if ((int)s.size() < n) s += y;
            if ((int)s.size() < n) s += y;
            if ((int)s.size() < n) s += z;
        }
    }

    s.resize(n);

    // 最后强行保证“答案 != |S|”
    // 如果整串里居然没有任何相邻相同字符，就随机找个位置改成一对
    bool ok = false;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
            ok = true;
            break;
        }
    }

    if (!ok && n >= 2) {
        int p = randint(0, n - 2);
        char c = rand_char();
        s[p] = s[p + 1] = c;
    }

    cout << s << '\n';
    return 0;
}
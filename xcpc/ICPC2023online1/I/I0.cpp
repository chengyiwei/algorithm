#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define endl '\n'
#define bit(x) (1ll << x)
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e16;
const int MOD = 998244353;
int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}
 
int sub(int x, int y)
{
    return add(x, MOD - y);
}
 
int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}
 
int binpow(int x, int y)
{
    int z = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}
 
int inv(int x)
{
    return binpow(x, MOD - 2);
}
 
int divide(int x, int y)
{
    return mul(x, inv(y));
}
 
 
int my_hash(char ch)//对字符进行哈希
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch - 'a' + 10;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 36;
    }
    else
    {
        return ch - '0';
    }
}
int pos(int ch)//当前字符在二进制中的位置
{
    if (ch >= 10 && ch <= 35) // 小写表示第1位
    {
        return 1;
    }
    else if (ch >= 36 && ch <= 61) // 大写表示第2位
    {
        return 2;
    }
    else // 数字表示第0位
    {
        return 0;
    }
}
 
int dp[2][10][70]; // 当前状态为S且最后一个字符是 ch 的方案数
int last[10];      // 状态为S时 所有的字符方案数之和
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
 
    //初始化部分
    int S = 0;
    int now;
    int ch; // 当前填入的字符编号
    if (s[1] == '?')
    {
        for (ch = 0; ch <= 61; ch++) // 当前填入ch
        {
            now = S | bit(pos(ch)); // 填入s[i]后,当前的二进制状态
            dp[1][now][ch] = 1;
        }
    }
    else
    {
        now = S | bit(pos(my_hash(s[1]))); // 填入s[i]后,当前的二进制状态
        ch = my_hash(s[1]);
        dp[1][now][ch] = 1; // 加上全部的
        if (s[1] >= 'a' && s[1] <= 'z')//如果是小写字母,还可以是大写字母
        {
            now = S | bit(pos(my_hash(s[1]) + 26)); // 填入s[i]后,当前的二进制状态
            ch = my_hash(s[1]) + 26;                // 填大写字母
            dp[1][now][ch] = 1;                     // 加上全部的
        }
    }
 
 
    for (int i = 2; i <= n; i++)
    {
        for (int S = 0; S < 8; S++)//
        {
            int sum = 0;
            for (int ch = 0; ch <= 61; ch++)
            {
                dp[0][S][ch] = dp[1][S][ch]; // 滚动数组
                dp[1][S][ch] = 0;            // 进行初始化
                sum = add(sum, dp[0][S][ch]);//表示上一层状态为S的所有字符的方案数
            }
            last[S] = sum; // 表示上一层状态为S的所有字符的方案数
        }
 
        for (int S = 0; S < 8; S++) // 枚举上一层的状态
        {
            int now;//表示填入字符后的状态
            int ch; // 当前填入的字符编号
            if (s[i] == '?')
            {
                for (ch = 0; ch <= 61; ch++) // 当前填入ch
                {
                    now = S | bit(pos(ch));                             // 填入s[i]后,当前的二进制状态
                    dp[1][now][ch] = add(dp[1][now][ch], last[S]);      // 加上全部的
                    dp[1][now][ch] = sub(dp[1][now][ch], dp[0][S][ch]); // 相邻不能相同，减去
                }
            }
            else
            {
                now = S | bit(pos(my_hash(s[i]))); // 填入s[i]后,当前的二进制状态
                ch = my_hash(s[i]);
                dp[1][now][ch] = add(dp[1][now][ch], last[S]);      // 加上全部的
                dp[1][now][ch] = sub(dp[1][now][ch], dp[0][S][ch]); // 相邻不能相同，减去
 
                if (s[i] >= 'a' && s[i] <= 'z') // 填入大写的
                {
                    now = S | bit(pos(my_hash(s[i]) + 26)); // 填入s[i]后,当前的二进制状态
                    ch = my_hash(s[i]) + 26;
                    dp[1][now][ch] = add(dp[1][now][ch], last[S]);      // 加上全部的
                    dp[1][now][ch] = sub(dp[1][now][ch], dp[0][S][ch]); // 相邻不能相同，减去
                }
            }
        }
    }
    int ans = 0;
    for (int ch = 0; ch <= 61; ch++)
    {
        ans = add(ans, dp[1][7][ch]);
    }
    cout << ans << endl;
}
signed main()
{
    freopen ("I.in", "r", stdin);
    freopen ("I0.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;


const int N = 5e2+10, M = 30010;

int s[20][N][N];

string t[N];

void solve()
{
    // cout<<setiosflags(ios::fixed)<<setprecision(10);
    int n, m, q;
    cin>>n>>m>>q;
    char temp[] = "der";
    int idx = 0;
    for(int i = 1 ;i <= n ;i++) cin>>t[i], t[i] = '$' + t[i];
    do
    {
        for(int i = 1; i <= n ;i++)
        {
            for(int j = 1; j <= m ;j++)
            {
                char need = temp[((i - 1) % 3 - (j - 1) % 3 + 3) % 3];
                if(need != t[i][j]) s[idx][i][j]++;
                s[idx][i][j] += s[idx][i - 1][j] + s[idx][i][j - 1] - s[idx][i - 1][j - 1];
            }
        }
        idx++;
        for(int i = 1; i <= n ;i++)
        {
            for(int j = 1; j <= m ;j++)
            {
                char need = temp[((i - 1) % 3 + (j - 1) % 3) % 3];
                if(need != t[i][j]) s[idx][i][j]++;
                s[idx][i][j] += s[idx][i - 1][j] + s[idx][i][j - 1] - s[idx][i - 1][j - 1];
            }
        }
        idx++;
    } while (next_permutation(temp, temp + 3));
    while(q--)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int ans = 0x3f3f3f3f;
        for(int i = 0 ;i < idx; i++)
        {
            ans = min(ans, s[i][x2][y2] - s[i][x1 - 1][y2] - s[i][x2][y1 - 1] + s[i][x1 - 1][y1 - 1]);
        }
        if(x2 - x1 + 1 == 2 && y2 - y1 + 1 == 2)
        {
            for(int i = 0 ;i < 3;i ++)
            {
                for(int j = 0; j < 3; j ++)
                {
                    if (i != j)
                    {
                        int cur = 0;
                        cur += (t[x1][y1] != temp[i]);
                        cur += (t[x2][y1] != temp[j]);
                        cur += (t[x1][y2] != temp[j]);
                        cur += (t[x2][y2] != temp[i]);
                        ans = min(ans, cur);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}

int main()
{
    freopen("K.in", "r", stdin);
    freopen("K0.out", "w", stdout);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
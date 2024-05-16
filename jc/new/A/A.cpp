#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
const int maxn = 1e4 + 10;
typedef long long ll;
int T, n, m;
int a[maxn];
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int i = n - 1;
        int ans = 0;
        for(; i >= 3; i -= 2)
        {
        //策略一：最快的和次快的先过河(时间a[1])，然后最快的回来送灯(a[0])，最慢的和次慢的过河a[i]，然后次快的回来送灯a[1];
            int time1 = a[1] + a[0] + a[i] + a[1];
        //策略二：由最快的和最慢的过河(时间a[i])，然后最快的回来送灯(a[0])，次慢的和最慢的过河a[i-1]，然后最快的回来送灯a[0];
            int time2 = a[i] + a[0] +a[i - 1] + a[0];
            ans += min(time1, time2);
        }
        if(i == 2)ans += a[0] + a[1] + a[2];
        else if(i == 1)ans += a[1];
        else ans += a[0];
        cout<<ans<<endl;
    }
    return 0;
}
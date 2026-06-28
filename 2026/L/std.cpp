#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve()
{
    string s;
    cin>>s;
    int l=s.size();
    stack<int>st;
    for(int i=0;i<l;i++)
    {
        if(st.empty()) st.push(s[i]);
        else{
            char a=st.top();
        char b=s[i];
        if(a==b)
        {
            st.pop();
        }
        else st.push(s[i]);
        }
    }
    cout<<st.size();
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
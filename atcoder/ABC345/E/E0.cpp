/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
*/
/*
  Credits -
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/ (namespace atcoder)
  Github source code of library - https://github.com/atcoder/ac-library/tree/master/atcoder
  https://codeforces.com/contest/4/submission/150120627
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define dbg(args...) 42;
    #define endl "\n"
#endif

// y_combinator from @neal template https://codeforces.com/contest/1553/submission/123849801
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int> c(n+1),v(n+1);
    for(int i=1;i<=n;i++)
        cin>>c[i]>>v[i];

    using ll = long long int;
    using ii = pair<ll,ll>;

    const ll inf = 1e15;
    vector<ii> infVec = {{-inf,-1},{-inf,-2}};
    vector<vector<vector<ii>>> dp(2);

    dp[0].resize(k+1,infVec);
    dp[1].resize(k+1,infVec);

    // 0 for base case
    dp[0][0][0].first=0;
    dp[0][0][1].first=0;

    for(int idx=1;idx<=n;idx++){
        const int currentColor = c[idx],currentValue=v[idx];
        auto &curDpVec=dp[idx&1],&pvrDpVec=dp[(idx-1)&1];

        for(int cnt=0;cnt<=k;cnt++){
            curDpVec[cnt][0].first=-inf;
            curDpVec[cnt][1].first=-inf;
            curDpVec[cnt][0].second=-1;
            curDpVec[cnt][1].second=-2;
        }

        // if we do not remove current element
        for(int removedCnt = 0; removedCnt<=k; removedCnt++){

            for(const auto &x:pvrDpVec[removedCnt]){
                const ll dpVal = x.first, pvrColor=x.second;
                if(pvrColor==currentColor)
                    continue;

                curDpVec[removedCnt].push_back({
                    currentValue+dpVal,currentColor
                });
                break;
            }
        }

        // if we remove current element
        for(int removedCnt = 1; removedCnt<=k; removedCnt++){
            for(const auto &x:pvrDpVec[removedCnt-1]){
                const ll dpVal = x.first, pvrColor=x.second;
                curDpVec[removedCnt].push_back({dpVal,pvrColor});
            }
        }

        // now remove duplicates if there exists in dp[idx][*]
        for(int removedCnt=0;removedCnt<=k;removedCnt++){
            auto &a=curDpVec[removedCnt];
            sort(a.begin(),a.end());
            reverse(a.begin(),a.end());
            if(a[0].second==a[1].second){  // a[0] 的颜色和 a[1] 的颜色相同
                ll secMaxVal = -inf,secMaxCol=-2;
                for(auto x:a){
                    if(x.second==a[0].second)
                        continue;
                    secMaxVal=x.first;
                    secMaxCol=x.second;
                    break;
                }
                a[1]={secMaxVal,secMaxCol};
            }
            a.resize(2);
        }
    }

    ll ans = dp[n&1][k][0].first;
    if(ans<0)
        ans=-1;
    cout<<ans<<endl;

    return 0;
}

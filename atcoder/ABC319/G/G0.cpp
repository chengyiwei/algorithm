#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
    int t,s,g;
}a[505];
int x;
vector<int>g[505];
int fa[505];
int Cnt;
int dp[(1<<10)+5];
int kop[(1<<10)+5];
int M[505];
void dfs(int x)
{
    if(a[x].t==1)
    {
        M[x]=a[x].s;
    }
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        M[v]=max(M[v],M[x]);
        dfs(v);
    }
}
vector<pair<int,int > >V;
int Pm[15];
signed main()
{
    freopen("G.in","r",stdin);
    freopen("G0.out","w",stdout);
    // freopen("date.in","r",stdin);
    // freopen("date.out","w",stdout);
    scanf("%lld",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%lld %lld %lld %lld",&x,&a[i].t,&a[i].s,&a[i].g);
        fa[i]=x;
        g[x].push_back(i);
        if(a[i].t==2)
        {
            a[i].s=++Cnt;
            Pm[Cnt]=i;
        }
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(a[i].t==1)
        {
            V.push_back(make_pair(M[i],i));
        }
    }
    sort(V.begin(),V.end());
    dp[0]=1;
    kop[0]=V.size();
    for(int i=0;i<V.size();i++)
    {
        if(dp[0]>=V[i].first)
        {
            dp[0]+=a[V[i].second].g;
        }
        else
        {
            kop[0]=i;
            break;
        }
    }
    if(kop[0]==V.size())
    {
        printf("Yes\n");
        return 0;
    }
    for(int S=0;S<(1<<Cnt);S++)
    {       
        for(int i=1;i<=Cnt;i++)
        {
            if((M[fa[Pm[i]]]<=dp[S])&&(!((S>>(i-1))&1)))
            {
                int Now=dp[S]*a[Pm[i]].g;
                int Kn=V.size();
                for(int j=kop[S];j<V.size();j++)
                {
                    if(Now>=V[j].first)
                    {
                        Now+=a[V[j].second].g;
                    }
                    else
                    {
                        Kn=j;
                        break;
                    }
                }
                if(Kn==V.size())
                {
                    printf("Yes\n");
                    return 0;
                }
                if(Now>dp[S|(1<<(i-1))])
                {
                    dp[S|(1<<(i-1))]=Now;
                    kop[S|(1<<(i-1))]=Kn;
                }
            }
        }
    }
    printf("No\n");
}
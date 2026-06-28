#include<iostream>
#include<vector>
#include<set>
#define int long long
using namespace std;
const int N = 1e6+5;


void solve()
{
   int n;cin>>n;
   double sum=0;
   for(int i=0;i<n;i++)
   {
    double x;cin>>x;
    sum=sum/2+x;
    if(sum==0) cout<<0;
    else if(sum>0) cout<<'+';
    else cout<<'-';
   }
}

int32_t main()
{
 ios::sync_with_stdio(false);
 cin.tie(0),cout.tie(0);
 
 int t;//cin>>t;
 t=1;
 while(t--) solve();
}
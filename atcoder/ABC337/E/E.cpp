#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m=0;
    while((1<<m) < n) m++;
    cout<<m<<endl;
    vector<vector<int> > p(m+1,vector<int>());
    vector<int> vis(n+1,1);
    for(int i=1;i<n;i++){
        int x = i;
        for(int j=1;j<=m;j++)
            if((x>>(j-1))&1) p[j].push_back(i);
    }
    for(int i=1;i<=m;i++){
        cout<<p[i].size()<<" ";
        for(int j=0;j<p[i].size();j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }
    char ch;
    for(int i=1;i<=m;i++){
        cin>>ch;
        if(ch == '0'){
            for(int j=0;j<p[i].size();j++)
                vis[p[i][j]] = 0;
        }
    }
    int ans = -1;
    for(int i=1;i<n;i++)
        if(vis[i]) ans = i;
    if(ans == -1) cout<<n<<endl;
    else cout<<ans<<endl;
    return 0;
}
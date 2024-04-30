#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int cnt;

int main(){
    freopen("L.in","r",stdin);
    int n;scanf("%d",&n);
    vector<vector<string> > s(n+1,vector<string>());
    vector<int> a(n+1);
    vector<string> nxt_s;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i].assign(a[i]+1,"");
        for(int j=1;j<=a[i];j++){
            cin>>s[i][j];
            if(!mp.count(s[i][j])) mp[s[i][j]]=++cnt;
        }
    }
    
    vector<map<string,int> > nxt(cnt+1,map<string,int>());
    for(int i=1;i<=n;i++){
        for(int j=1;j<a[i];j++){
            int x=mp[s[i][j]];
            if(!nxt[x].count(s[i][j+1])) nxt[x][s[i][j+1]]=1;
            else nxt[x].at(s[i][j+1])++;
        }
    }

    nxt_s.assign(cnt+1,"");
    for(auto it_s=mp.begin();it_s!=mp.end();++it_s){
        int x=mp[it_s->first];
        int max_x=0;
        for(auto it=nxt[x].begin();it!=nxt[x].end();++it){
            if(it->second>max_x){
                max_x=it->second;
                nxt_s[x]=it->first;
            }
        }
    }

    int q;scanf("%d",&q);
    while(q--){
        string now_s;cin>>now_s;
        for(int i=1;i<=21;i++){
            printf("%s ",now_s.c_str());
            if(nxt_s[mp[now_s]].empty()) break;
            now_s=nxt_s[mp[now_s]];
        }
        printf("\n");
    }
    return 0;
}
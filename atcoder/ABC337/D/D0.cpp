#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

char read_ch(){
    char ch=getchar();
    while(ch!='.'&&ch!='o'&&ch!='x') ch=getchar();
    return ch;
}

int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int n = read(), m = read(), k = read();
    vector<vector<int> > a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j] = read_ch();
    int ans = INF;
    
    if(k <= m)
        for(int i=1;i<=n;i++){
            int num_ = 0,num_x = 0;
            for(int j=1;j<=k;j++){
                if(a[i][j]=='.') num_++;
                if(a[i][j]=='x') num_x++;
            }
            if(num_x==0) ans = min(ans,num_);
            for(int j=k+1;j<=m;j++){
                int t_1 = j-k, t_2 = j;
                if(a[i][t_1]=='.') num_--;
                if(a[i][t_1]=='x') num_x--;
                if(a[i][t_2]=='.') num_++;
                if(a[i][t_2]=='x') num_x++;
                if(num_x==0) ans = min(ans,num_);
            }
        }

    if(k <= n)
        for(int j=1;j<=m;j++){
            int num_ = 0,num_x = 0;
            for(int i=1;i<=k;i++){
                if(a[i][j]=='.') num_++;
                if(a[i][j]=='x') num_x++;
            }
            if(num_x==0) ans = min(ans,num_);
            for(int i=k+1;i<=n;i++){
                int t_1 = i-k, t_2 = i;
                if(a[t_1][j]=='.') num_--;
                if(a[t_1][j]=='x') num_x--;
                if(a[t_2][j]=='.') num_++;
                if(a[t_2][j]=='x') num_x++;
                if(num_x==0) ans = min(ans,num_);
            }
        }

    printf("%d\n",ans == INF ? -1 : ans);
    return 0;
}
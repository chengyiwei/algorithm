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
    vector<vector<int> > a(n+5,vector<int>(m+5));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j] = read_ch();
    int ans = INF;
    
    for(int i=1;i<=n;i++){
        int r = 0;
        int now_ans = 0, now_k = 0;
        for(int j=1;j<=m;j++){
            while(r + 1 <= m && now_k < k) {
                if(a[i][r+1] == '.') now_ans++ , now_k++;
                if(a[i][r+1] == 'o') now_k++;
                r++;
            }
            if(now_k >= k && r-j+1 == k) ans = min(ans, now_ans);
            if(a[i][j] == '.') now_ans-- , now_k--;
            if(a[i][j] == 'o') now_k--;
        }
    }

    for(int j=1;j<=m;j++){
        int r = 0;
        int now_ans = 0, now_k = 0;
        for(int i=1;i<=n;i++){
            while(r + 1 <= n && now_k < k) {
                if(a[r+1][j] == '.') now_ans++ , now_k++;
                if(a[r+1][j] == 'o') now_k++;
                r++;                
            }
            if(now_k >= k && r-i+1==k) ans = min(ans, now_ans);
            if(a[i][j] == '.') now_ans-- , now_k--;
            if(a[i][j] == 'o') now_k--;
        }
    }

    printf("%d\n",ans == INF ? -1 : ans);
    return 0;
}
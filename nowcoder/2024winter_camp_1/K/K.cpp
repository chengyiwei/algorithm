#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
struct node{int x;char s[10];}a[maxn];
const LL TT = 998244353;
vector<int> G[maxn];
int du[maxn],n;
LL ans = 1;

void topo(){
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!du[i]) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        du[a[x].x]--;
        if(!du[a[x].x]) q.push(a[x].x);
    }
}

int main(){
    freopen("K.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%*c%s",&a[i].x,a[i].s);
        du[a[i].x]++;
    }
    topo();
    for(int i=1;i<=n;i++) if(du[i]){
        LL now_ans = 0;
        for(int k=0;k<5;k++){
            int p = a[i].x, op = a[i].s[k]-'A';
            while(p != i){
                op = a[p].s[op]-'A', p = a[p].x;
            }
            now_ans += (op == k);
        }
        ans = (ans * now_ans) % TT;
        du[i] = 0;
        for(int p=a[i].x;p!=i;p=a[p].x)
            du[p] = 0;
    }
    printf("%lld\n",ans);
    return 0;
}
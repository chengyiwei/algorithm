#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
struct node{
    int x,id,ans;
}a[maxn];
bool cmp1(node A,node B){return A.x<B.x;}
bool cmp2(node A,node B){return A.id<B.id;}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].id=i;
    sort(a+1,a+1+n,cmp1);
    int lst=0;
    long long lst_sum=0;

    for(int i=1;i<=n;i++){
        if(lst_sum<a[i].x){
            for(int j=i-1;j>lst;j--)
                a[j].ans=i-1-1;
            lst=i-1;
        }
        lst_sum+=a[i].x;
    }
    for(int i=lst+1;i<=n;i++)
        a[i].ans=n-1;
    sort(a+1,a+1+n,cmp2);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].ans);
    printf("\n");return ;
}
int main(){
    freopen("B.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
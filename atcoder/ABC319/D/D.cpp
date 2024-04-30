#include<bits/stdc++.h>
using namespace std;
int N, a[200005],M;
long long L = 1, R = 0, ans = (long long)1<<60;
bool check(long long now){
    int ret = 1;
    long long pos = 0;
    for (int i = 1; i <= N;i++){
        if(pos+a[i]>now){
            ret += 1;
            pos = a[i];
        }
        else{
            pos += a[i];
        }
        pos++;
    }
    return ret <=M;
}
int main(){
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    scanf("%d%d", &N,&M);
    for (int i = 1; i <= N;i++){
        scanf("%d", &a[i]);
        R =R+a[i];
        L = max(L, (long long)a[i]);
    }
    R += N;
    while(L<=R){
        long long mid = (R + L) /2;
        if(check(mid)){
            ans = min(ans, mid);
            R = mid - 1;
        }
        else
            L = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
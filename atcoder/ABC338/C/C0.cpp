#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main(){
    freopen("C.in","r",stdin);
    freopen("C0.out","w",stdout);
    int n; scanf("%d",&n);
    vector<int> a(n+1),b(n+1),q(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&q[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    int ans = 0;
    for(int num_a=0;num_a<=1e3;num_a++){  // num_a 个 a
        for(int num_b=0;num_b<=1e3;num_b++){  // num_b 个 b
            int flg = 1;
            for(int i=1;i<=n;i++){
                if(num_a * a[i] + num_b * b[i] > q[i]) {
                    flg = 0;
                    break;
                }
            }
            if(flg) ans = max(ans, num_a + num_b);
        }
    }
    printf("%d\n",ans);
    return 0;
}
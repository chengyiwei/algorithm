#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("H.in","r",stdin);
    freopen("H.out","w",stdout);
    int n;
    scanf("%d",&n);
    double S = 200 * 200, s = S/2, L = sqrt(s)/2;
    int ret =  0;
    for(int i=1;i<=n;i++){
        double x,y,r;
        scanf("%lf%lf%lf",&x,&y,&r);
        if(-L<x && x<L && -L<y && y<L) ret++;
    }
    if((double)ret/n > 0.55) printf("buaa-noob\n");
    else printf("bit-noob\n");
    // printf("%.2lf", (double)ret/n);
}
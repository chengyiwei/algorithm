#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<double> p(n+1,0);
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
    double ans=0;
    for(int i=1;i<=n;i++){
        double sum=0;
        for(int j=1;j<=n;j++)if(i!=j){
            sum+=p[i]/(p[i]+p[j]);
        }
        ans+=sum*p[i];
    }
    printf("%.10lf\n",ans);
}
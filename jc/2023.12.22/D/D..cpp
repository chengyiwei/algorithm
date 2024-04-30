#include<bits/stdc++.h>
using namespace std;

struct AS{
    int L,R;
    bool operator<(const AS &a)const{return L<a.L;}
};
int main(){
    freopen("D.in","r",stdin);
    int n;
    scanf("%d",&n);
    vector<AS> x;
    for(int i=1;i<=n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        x.push_back({l,r});
    }
    sort(x.begin(),x.end());
    vector<int> F;
    for(int i=0;i<n;i++){
        if(F.size()==0||F[F.size()-1]<x[i].R) F.push_back(x[i].R);
        else *lower_bound(F.begin(),F.end(),x[i].R)=x[i].R;
    }
    printf("%d\n",F.size());
    return 0;
}
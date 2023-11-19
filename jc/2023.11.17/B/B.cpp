#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=1e9+7;
struct Mar{
    LL a[2][2];
    Mar(){memset(a,0,sizeof a);}
};
Mar operator * (Mar A,Mar B){
    Mar ret;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++){
        ret.a[i][j]+=(A.a[i][k]*B.a[k][j]%TT+TT)%TT;
        ret.a[i][j]=(ret.a[i][j]+TT)%TT;
    }
    return ret;
}
Mar Pow(Mar a,LL b){
    Mar ret;
    ret.a[0][0]=1;
    ret.a[1][1]=1;
    while(b){
        if(b&1) ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}
int main(){
    freopen("B.in","r",stdin);
    LL N;
    cin>>N;
    if(N==1){printf("1\n");return 0;}
    if(N==2){printf("8\n");return 0;}
    Mar base,st,ed;
    base.a[0][1]=1;base.a[1][0]=1;base.a[1][1]=7;
    st.a[0][0]=1;st.a[0][1]=7;
    Mar ans=Pow(base,N-2);
    ed=st*ans;
    cout<<(ed.a[0][0]+ed.a[0][1])%TT;
    return 0;
}
#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int maxn= 200005;
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret;
}
inline void print(int x, int flag = 1)
{
    if (x < 0) putchar('-'), x = ~(x - 1);
    if (x > 9) print(x / 10, 0);
    putchar(x % 10 + 48);
    if (flag) putchar(flag & 1 ? ' ' : '\n');
}
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
inline int lcm(int x,int y) {return x/gcd(x,y) *y;}
int N,x,y,z,F[maxn][8],tmp[8],w[8];
signed main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    N=read();x=read();y=read();z=read();
    w[1]=x;w[2]=y;w[4]=z;w[3]=lcm(x,y);w[5]=lcm(x,z);w[6]=lcm(y,z);w[7]=lcm(x,lcm(y,z));
    memset(F,0x7f,sizeof F);F[0][0]=0;
    for(int i=1;i<=N;i++){
        int now=read();
        for(int j=1;j<8;j++)
            tmp[j]=(w[j]-(now%w[j]))%w[j];
        F[i][0]=0;
        for(int j=0;j<8;j++){
            F[i][j]=min(F[i][j],F[i-1][j]);
            for(int k=1;k<8;k++)
                F[i][j|k]=min(F[i][j|k],F[i-1][j]+tmp[k]);
        }
    }
    print(F[N][7]);
    return 0;
}
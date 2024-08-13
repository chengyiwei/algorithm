#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int Aa,Bb,Cc,Dd,Ad,Bd,Cd,Da,Db,Dc;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    freopen("D.in","r",stdin);
    a=read();b=read();c=read();d=read();
    int ans=0;
    Aa=read();Ad=read();
    Bb=read();Bd=read();
    Cc=read();Cd=read();
    Da=read();Db=read();Dc=read();Dd=read();
    for(int num_sum=0;num_sum<=300;num_sum++){
        for(int num_A=0;num_A<=num_sum;num_A++){
            for(int num_B=0;num_B+num_A<=num_sum;num_B++){
                for(int num_C=0;num_A+num_B+num_C<=num_sum;num_C++){
                    int num_D=num_sum-num_A-num_B-num_C;
                    int now_a=num_A*Aa+num_D*Da;
                    int now_b=num_B*Bb+num_D*Db;
                    int now_c=num_C*Cc+num_D*Dc;
                    int now_d=num_A*Ad+num_B*Bd+num_C*Cd+num_D*Dd;

                    if(now_a>a) now_b+=(now_a-a)/5,now_a-=((now_a-a)/5)*5;
                    if(now_b>b) now_c+=(now_b-b)/5,now_b-=((now_b-b)/5)*5;

                    if(now_a>=a&&now_b>=b&&now_c>=c&&now_d>=d){
                        // printf("%d %d %d %d %d\n",num_A+num_B+num_C+num_D,num_A,num_B,num_C,num_D);
                        // return 0;
                    }
                }
            }
        }
    }
    return 0;
}
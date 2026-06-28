#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

void solve(){
    int n=read(),m=read();
    int x_a=read(),y_a=read();
    int x_b=read(),y_b=read();
    if(x_a > x_b) {printf("Draw\n");return ;}
    if((x_a - x_b)%2 == 0){ //Bob 赢
        int mid_x=(x_a+x_b)/2;
        int A_L = max(1,y_a-(mid_x-x_a)) , A_R = min(m,y_a+(mid_x-x_a));
        int B_L = max(1,y_b-(x_b-(mid_x+1))), B_R = min(m,y_b+(x_b-(mid_x+1)));
        if((B_L-1 <= A_L) && (B_R+1 >= A_R)) printf("Bob\n");
        else printf("Draw\n");
    }
    else{ //Alice 赢
        int mid_x=(x_a+x_b)/2;
        int A_L = max(1,y_a-(mid_x-x_a)) , A_R = min(m,y_a+(mid_x-x_a));
        int B_L = max(1,y_b-(x_b-(mid_x+1))), B_R = min(m,y_b+(x_b-(mid_x+1)));
        if((A_L-1 <= B_L) && (A_R+1 >= B_R)) printf("Alice\n");
        else printf("Draw\n");
    }
}

int main(){
    freopen("E.in","r",stdin);
    int T=read();
    while(T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int N;
    cin>>N;
    char s[25],lst;
    scanf("%s",s+1);
    int A_win=0,B_win=0;
    int num_A,num_B,num_A_win=0,num_B_win=0;
    for(int y=1;y<=N;y++){
        num_A=num_B=0;num_A_win=0,num_B_win=0;
        for(int i=1;i<=N;i++){
            if(s[i]=='A')num_A++;
            else num_B++;
            if(num_A==y) {num_A_win++;num_A=0,num_B=0;lst='A';}
            else if(num_B==y) {num_B_win++;num_A=0;num_B=0;lst='B';}
        }
        if(num_A||num_B) continue;
        if(num_A_win==num_B_win+1&&lst=='A') 
            A_win=1;
        else if(num_A_win+1==num_B_win&&lst=='B') 
            B_win=1;
        else ;
    }
    if(A_win&&B_win) {printf("?\n");return ;}
    if(A_win==1&&B_win==0) {printf("A\n");return ;}
    if(A_win==0&&B_win==1) {printf("B\n");return ;}
    printf("?\n");return ;
}
int main(){
    freopen("A.in","r",stdin);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
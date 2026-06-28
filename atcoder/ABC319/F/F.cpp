#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=505,maxe=(1<<10)+5;
struct enemy{
    int type;
    LL g,pos;
    bool operator <(const enemy B){return g<B.g;}
} E[maxn];
enemy m[maxn],len_m;
void put(enemy now){
    m[++len_m]=now;int sonn=len_m;
    while(son>1){
        if(m[son]<m[son>>1]) swap(m[son],m[son>>1]),son>>=1;
        else break;
    }
    return ;
}
enemy get(){
    enemy ret=m[1]; int fa=1;
    while((fa<<1)>len_m){
        if((fa<<1|1)>len_m||m[fa<<1]<m[fa<<1|1]){
            if(m[fa<<1]<m[fa]){swap(m[fa<<1],m[fa]);fa<<=1;}
            else break;
        }
        else{
            if(m[fa<<1|1]<m[fa]){swap(m[fa<<1|1],m[fa]);fa=fa<<1|1;}
            else break;
        } 
    }
    return ret;
}
int cnt,nxt[maxn],lnk[maxn],son[maxn],father[maxn];
inline void add_e(int x,int y){
    son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;
}
int main(){
    N=read();
    for(int i=2;i<=N;i++){
        father[i]=read();
        
    }
}
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<iomanip>
#include<cmath>
#define R register
#define rep(i,a,b) for(R int i=a;i<=b;i++)
#define delta 0.996
#define maxn 50005
using namespace std;

inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-f;ch=getchar();}
    while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}

struct node{
    double x,y;
}poi[maxn];
int T,n;
double ansx,ansy,ax,ay,ans,t;

void clear() {
    ax=0,ay=0;
    ans=1e8;
}

double calculate(double x,double y) {  
    double res=0;
    rep(i,1,n) {
        double dx=x-poi[i].x,dy=y-poi[i].y;
        res+=sqrt(dx*dx+dy*dy);
    }
    return res;
}

void simulate_anneal() {
    double x=ansx,y=ansy;
    t=3000; //设置初始温度
    while(t>1e-15) {
        double X=x+((rand()<<1)-RAND_MAX)*t;  //每次的该变量与 现在的温度 t 有关
        double Y=y+((rand()<<1)-RAND_MAX)*t;
        double now=calculate(X,Y); // 计算答案
        double Delta=now-ans;  // 计算 E 的该变量
        if(Delta<0) { // 选择是否接受
            ansx=X,ansy=Y;
            x=X,y=Y;
            ans=now;
        } else {
	        if(exp(-Delta/t)*RAND_MAX>rand()) 
		        x=X,y=Y;
		}
        t*=delta;  //降温
    }
}

void work() {//进行五次退火
    ansx=ax/n,ansy=ay/n;
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
}

int main() { 
    srand(1e9+7);  // 随机化种子填一个幸运数字
    T=read();
    rep(i,1,T) {
        n=read();
        clear();
        rep(j,1,n) {
            poi[j].x=read(),poi[j].y=read();
            ax+=poi[j].x,ay+=poi[j].y;
        }
        work();  //开始退火
        cout<<round(ans)<<'\n';
        if(i!=T) cout<<'\n';
    }
    return 0;
}
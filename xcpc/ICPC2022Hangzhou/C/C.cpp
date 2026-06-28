#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int N,K;
int F[maxn][maxn][2],w[15];
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
    freopen("C.in","r",stdin);
    N=read();K=read();
    
    memset(F,-0x3f,sizeof F);
    F[0][0][0]=0;
    for(int i=1;i<=N;i++){
        int p=read();
        for(int j=1;j<=p;j++) w[j]=read();
        for(int j=K-1;j>=0;j--){
            F[i][j][0]=F[i-1][j][0];F[i][j][1]=F[i-1][j][1];
            if(j+p<=K){ 
                F[i][j+p][0]=max(F[i][j+p][0],F[i-1][j][0]+w[p]);
                F[i][j+p][1]=max(F[i][j+p][1],F[i-1][j][1]+w[p]);
            }
            for(int now_k=1;now_k<p;now_k++){
                if(j+now_k<=K){
                    F[i][j+now_k][1]=max(F[i][j+now_k][1],F[i-1][j][0]+w[now_k]);
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++)
    for(int j=0;j<=K;j++){
        ans=max(ans,F[i][j][0]);
        if(j==K) ans=max(ans,F[i][j][1]);
    }
    printf("%d\n",ans);
    return 0;
}
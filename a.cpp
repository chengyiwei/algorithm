#pragma GCC optimize(2)
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M,T,K;
int mp[2][505][505],line[2005][3],node[2005][2],id[2005],G[2005][2005],dis[260105],vis[260105],cnt,F[2005][2005],ans;
struct edge{
	int x,w;
	bool operator <(const edge B)const {return w<B.w;}
}hep[260105];
int hep_len;
vector<edge> e[260105];
inline void add_e(int x,int y,int z){
	e[x].push_back((edge){y,z});
}
inline void add_edge(int x,int y,int z){
	e[x].push_back((edge){y,z});e[y].push_back((edge){x,z});
}
struct IO{
    static const int S=1<<21;
    char buf[S],*p1,*p2;int st[105],Top;
    ~IO(){clear();}
    inline void clear(){fwrite(buf,1,Top,stdout);Top=0;}
    inline void pc(const char c){Top==S&&(clear(),0);buf[Top++]=c;}
    inline char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    inline IO&operator >> (char&x){while(x=gc(),x==' '||x=='\n'||x=='r');return *this;}
    template<typename T>inline IO&operator >> (T&x){
        x=0;bool f=0;char ch=gc();
        while(ch<'0'||ch>'9'){if(ch=='-') f^=1;ch=gc();}
        while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=gc();
        f?x=-x:0;return *this;
    }
    inline IO&operator << (const char c){pc(c);return *this;}
    template<typename T>inline IO&operator << (T x){
        if(x<0) pc('-'),x=-x;
        do{st[++st[0]]=x%10,x/=10;}while(x);
        while(st[0]) pc('0'+st[st[0]--]);return *this;
    }
}fin,fout;
inline int calc(int x,int y){return (x-1)*(M-1)+y;}
bool cmp(int x,int y){return line[x][0]<line[y][0];}
int Nxt(int x){
	return x==(N+M<<1)?1:x+1;
}
void update_edge(int x,int y,int z){
	int flg=0;
	vector<edge>::iterator it=e[x].begin();
	for(;it!=e[x].end();++it){
		if(it->x==y){
			if(it->w==z){flg=1;break;}		
			else {e[x].erase(it);break;}
		}
	}
	if(!flg)add_e(x,y,z);
	it=e[y].begin();flg=0;
	for(;it!=e[y].end();++it){
		if(it->x==x){
			if(it->w==z){flg=1;break;}
			else {e[y].erase(it);break;}
		}
	}
	if(!flg)add_e(y,x,z);
	return ;
}
void put(edge x){
	hep[++hep_len]=x;int son=hep_len;
	while(son>1&&hep[son]<hep[son>>1]) swap(hep[son],hep[son>>1]),son>>=1;
	return ;
}
edge get(){
	edge ret=hep[1];int son,fa=1;hep[1]=hep[hep_len--];
	while((fa<<1)<=hep_len){
		if((fa<<1)>hep_len||hep[fa<<1]<hep[fa<<1|1]) son=fa<<1;else son=fa<<1|1;
		if(hep[son]<hep[fa]) swap(hep[son],hep[fa]),fa=son;else break;
	}
	return ret;
}
void dij(int s){
	memset(dis,63,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;edge now;now.x=s;now.w=0;hep_len=0;
	put(now);
	while(hep_len){
		edge tmp=get();
		int x=tmp.x;
		if(vis[x])continue;vis[x]=1;
		for(int i=0,sz=e[x].size();i<sz;++i)
			if(!vis[e[x][i].x]&&dis[e[x][i].x]>dis[x]+e[x][i].w){
				dis[e[x][i].x]=dis[x]+e[x][i].w;
				now.x=e[x][i].x;now.w=dis[e[x][i].x];
				put(now);
			}
	}
	return ;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	fin>>N>>M>>T;
	for(int i=1;i<N;i++)
	for(int j=1;j<=M;j++) fin>>mp[0][i][j];
	for(int i=1;i<=N;i++)
	for(int j=1;j<M;j++) fin>>mp[1][i][j];
	for(int i=1;i<N;i++)
	for(int j=1;j<M;j++){
		if(i!=N-1){add_edge(calc(i,j),calc(i+1,j),mp[1][i+1][j]);}
		if(j!=M-1){add_edge(calc(i,j),calc(i,j+1),mp[0][i][j+1]);}
	}
	for(int i=1;i<N;i++){
		add_edge(calc(i,1),(N-1)+(M-1<<1)+4+(N-1-i+1)+(N-1)*(M-1),mp[0][i][1]);
		add_edge(calc(i,M-1),(M-1)+2+(i)+(N-1)*(M-1),mp[0][i][M]);
	}
	for(int j=1;j<M;j++){
		add_edge(calc(1,j),j+1+(N-1)*(M-1),mp[1][1][j]);
		add_edge(calc(N-1,j),(N-1)+(M-1)+3+(M-1-j+1)+(N-1)*(M-1),mp[1][N][j]);
	}
	while(T--){
		fin>>K;
		memset(G,63,sizeof G);memset(F,63,sizeof F);ans=0x3f3f3f3f;cnt=0;
		for(int i=1;i<=K;i++) {int l,x,c;fin>>l>>x>>c;line[i][0]=x;line[i][1]=c;id[i]=i;line[i][2]=l;}
		if(K<=1){fout<<0<<'\n';continue;}
		sort(id+1,id+1+K,cmp);
		for(int i=1;i<=K;i++){
			int nx=i+1<=K?i+1:1;
			if(line[id[i]][1]==line[id[nx]][1]){
				for(int j=Nxt(line[id[i]][0]);j!=line[id[nx]][0];j=Nxt(j))update_edge(j+(N-1)*(M-1),Nxt(j)+(N-1)*(M-1),0);
				update_edge(line[id[nx]][0]+(N-1)*(M-1),Nxt(line[id[nx]][0])+(N-1)*(M-1),line[id[nx]][2]);
			}
			else{
				cnt++;
				node[cnt][0]=Nxt(line[id[i]][0])+(N-1)*(M-1);node[cnt][1]=line[id[i]][1];
				for(int j=Nxt(line[id[i]][0]);j!=line[id[nx]][0];j=Nxt(j))update_edge(j+(N-1)*(M-1),Nxt(j)+(N-1)*(M-1),0);
				update_edge(line[id[nx]][0]+(N-1)*(M-1),Nxt(line[id[nx]][0])+(N-1)*(M-1),line[id[nx]][2]);
			}
		}
		for(int i=1;i<=cnt;i++) {
			dij(node[i][0]);
			for(int j=1;j<=cnt;j++) if(i!=j) G[i][j]=min(G[i][j],dis[node[j][0]]);
		}
		for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++) G[i+cnt][j]=G[i][j+cnt]=G[i+cnt][j+cnt]=G[i][j];
		for(int i=1;i<(cnt<<1);i++) F[i][i+1]=G[i][i+1];
		for(int L=3;L<cnt;L+=2)
			for(int i=1,j;i+L<=cnt;i++){
				j=i+L;
				for(int k=i+1;k<=j;k+=2)F[i][j]=min(F[i][j],F[i][k]+F[k+1][j]);
				F[i][j]=min(F[i][j],G[i][j]+F[i+1][j-1]);
			}
		for(int i=1;i<=cnt;i++) ans=min(ans,F[i][i+cnt-1]);
		fout<<(ans==0x3f3f3f3f?0:ans)<<'\n';
	}
	return 0;
}
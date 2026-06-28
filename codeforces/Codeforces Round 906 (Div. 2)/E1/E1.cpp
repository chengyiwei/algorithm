#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int T,N,M,K,max_,num_0;
int hsh1[maxn],clr[maxn];
struct pa{
    int a,b;
    bool operator <(const pa B)const {return a>B.a;}
};
struct Line{
    int L,R,id;
    bool operator <(const Line B) const {return R>B.R;}
}a[maxn];
map<pa,int> hsh2;
priority_queue<Line> pq; 
bool cmp(Line A,Line B){
    return A.L<B.L;
}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("E1.in","r",stdin);
    T=read();
    while(T--){
        max_=0;num_0=0;
        while(!pq.empty()) pq.pop();
        memset(hsh1,0,sizeof hsh1);
        hsh2.clear();
        N=read();M=read();K=read();
        for(int i=1;i<=M;i++){
            a[i].L=read(),a[i].R=read();a[i].id=i;
        }
        sort(a+1,a+1+M,cmp);
        int pos=1;
        for(int i=1;i<=N;i++){
            while(pos<=M&&a[pos].L<=i) 
                pq.push(a[pos]),pos++;
            while((!pq.empty())){
                if(pq.top().R<i) 
                    pq.pop();
                else break;
            } 
            if(pq.empty())num_0++;
            else if(pq.size()==1){
                int now_id=pq.top().id;
                hsh1[now_id]++;
            }
            else if(pq.size()==2){
                Line now=pq.top();
                pq.pop();
                int now_id_1=now.id,now_id_2=pq.top().id;
                if(now_id_1>now_id_2) swap(now_id_1,now_id_2);
                hsh2[(pa){now_id_1,now_id_2}]++;
                pq.push(now);
            }
        }
        
        if(1){
            for(map<pa,int>::iterator it = hsh2.begin();it!=hsh2.end();++it){
                int now_1 = it->first.a,now_2=it->first.b;
                int now_s=it->second+hsh1[now_1]+hsh1[now_2];
                max_=max(max_,now_s);
            }
        }
        int max_1=0,max_2=0;
        for(int i=1;i<=M;i++){
            if(hsh1[i]>max_2) {
                if(hsh1[i]>max_1){
                    max_2=max_1;
                    max_1=hsh1[i];
                }
                else {
                    max_2=hsh1[i];
                }
            }
        }
        max_=max(max_,max_1+max_2);
        printf("%d\n",max_+num_0);
    }
    return 0;
}
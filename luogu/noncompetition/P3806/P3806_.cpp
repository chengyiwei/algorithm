// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 999999999
 
int n,m,len=0,Size;
struct node{int x,y,z,next;};
node e[20010];
int first[10010];
int root,ms,size[10010],mson[10010],sum[10000010];
bool v[10010];
void buildroad(int x,int y,int z)
{
    len++;
    e[len].x=x;
    e[len].y=y;
    e[len].z=z;
    e[len].next=first[x];
    first[x]=len;
}
void getroot(int x,int fa)//fa表示x的父亲，防止往回搜
{
    size[x]=1;mson[x]=0;//size[i]记录以i为根的子树的大小，mson[i]表示i节点的最大子树的大小 
    for(int i=first[x];i;i=e[i].next)
    {
        int y=e[i].y;
        if(v[y]||y==fa)continue;//v[y]表示当前节点是否被分治过，先别管这货，后面再讲 
        getroot(y,x);//往下继续搜索 
        size[x]+=size[y];//加上子树大小 
        if(size[y]>mson[x])mson[x]=size[y];//更新最大的子树 
    }
    if(Size-size[x]>mson[x])mson[x]=Size-size[x];
    //Size表示当前这整棵树的大小，那么Size-size[x]就表示不在x的子树内的节点数量，下面详解 
    if(ms>mson[x])ms=mson[x],root=x;//ms表示树的重心的最大子树的大小（相当于mson[root]），这一步是用来更新树的重心的，root用来记录重心 
}
int t;
int dis[10010];
int ask[110],ans[110];
void getdis(int x,int fa,int z)//fa表示x的父亲，z表示x到目标点的距离
{
    dis[++t]=z;//这里写dis[++t]=z而不是dis[x]=z是因为后面我们会发现每一个t对应哪一个x并不重要，也就是说我们只需要知道每一个点到目标点的距离，而不需要知道那个点是谁，看到后面就会明白的啦
    for(int i=first[x];i;i=e[i].next)
    {
        int y=e[i].y;
        if(y==fa||v[y])continue;//这里加个v[y]是因为不能往被分治过的点走，后面会讲的啦
        getdis(y,x,z+e[i].z);
    }
}
struct asd{int x,y;}arr[10010];
int tt;
bool cmp(int x,int y){return x<y;}
void solve(int x,int y,int id)//x表示getdis的起始点，y表示x到目标点的距离，id表示这一次统计出来的答案是合理的还是不合理的
{
    t=0;
    getdis(x,0,y);//算出树中的点到目标点的距离 
    tt=0;
    sort(dis+1,dis+t+1,cmp);
    dis[0]=-233;
    for(int i=1;i<=t;i++)
    if(dis[i]!=dis[i-1])arr[++tt].x=dis[i],arr[tt].y=1;
    else arr[tt].y++;
    for(int i=1;i<=m;i++)
    {
    	if(ask[i]%2==0)for(int j=1;j<=tt;j++)
    		if(arr[j].x==ask[i]/2)ans[i]+=(arr[j].y-1)*arr[j].y/2*id;
    	
    	for(int j=1;j<=tt&&arr[j].x<=ask[i]/2;j++)
    	{
    		int l=j+1,r=tt;
    		while(l<=r)
    		{
    			int mid=l+r>>1;
    			if(arr[j].x+arr[mid].x==ask[i])
    			{
    				ans[i]+=arr[j].y*arr[mid].y*id;
    				break;
                }
                if(arr[j].x+arr[mid].x>ask[i])r=mid-1;
                else l=mid+1;
            }
        }
    }
}
void fenzhi(int x,int ssize)//ssize是当前这棵子树的大小
{
    v[x]=true;//代码保证每次进来的x都必定是当前这棵树的重心，我们将v[x]标记为true，表示x点被分治过
    solve(x,0,1);//计算这棵树以x为重心的所有组合，solve函数后面会讲
    for(int i=first[x];i;i=e[i].next)
    {
        int y=e[i].y;
        if(v[y])continue;
        solve(y,e[i].z,-1);//计算不合法组合，用所有组合减去不合法组合
        ms=inf;root=0;//记得要初始化
        Size=size[y]<size[x]?size[y]:(ssize-size[x]);
        getroot(y,0);//求出以y为根的子树
        fenzhi(root,Size);
    }
}
 
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        buildroad(x,y,z);
        buildroad(y,x,z);
    }
    for(int i=1;i<=m;i++)
    scanf("%d",&ask[i]);
    root=0;ms=inf;Size=n;
    getroot(1,0);
    fenzhi(root,n);
    for(int i=1;i<=m;i++)
    if(ans[i]>0)printf("AYE\n");
    else printf("NAY\n");
}
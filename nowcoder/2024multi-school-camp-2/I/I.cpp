// Problem: Red Playing Cards
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/81597/I
// Memory Limit: 2097152 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define lowbit(i) ((i)&(-i))
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define ll long long
#define endl "\n"
#define vi vector<int> 
#define all(v) v.begin() + 1 , v.end()
#define pb push_back
#define vii vector <vector <int > > 
#define vp vector <pair <int , int > > 
typedef pair<int ,int > pii;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 6e3 + 10 , M = N * 2 ;

struct seg {
	int l , r , v , w ; 
}e[N] ; 

vector <int> have[N + 1] ; 

template<class Info, class Tag>
struct LSGT {
    #define l(p) (p << 1)
    #define r(p) (p << 1 | 1)
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LSGT() {}
    LSGT(int _n, Info _v = Info()) {
        init(_n, _v);
    }
    template<class T>
    LSGT(std::vector<T> _init) {
        init(_init);
    }
    void init(int _n, Info _v = Info()) {
        init(std::vector<Info>(_n, _v));
    }
    template<class T>
    void init(std::vector<T> _init) {
        n = _init.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1) {
                info[p] = _init[l];
                return;
            }
            int m = l + r >> 1;
            self(self, l(p), l, m);
            self(self, r(p), m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }
    void pull(int p) {
        info[p] = info[l(p)] + info[r(p)];
    }
    void apply(int p, const Tag &v, int len) {
        info[p].apply(v, len);
        tag[p].apply(v);
    }
    void push(int p, int len) {
        apply(l(p), tag[p], len / 2);
        apply(r(p), tag[p], len - len / 2);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        push(p, r - l);
        if (x < m) {
            modify(l(p), l, m, x, v);
        } else {
            modify(r(p), m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y or r <= x) {
            return Info();
        }
        if (l >= x and r <= y) {
            return info[p];
        }
        int m = l + r >> 1;
        push(p, r - l);
        return query(l(p), l, m, x, y) + query(r(p), m, r, x, y);
    }
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    void Apply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y or r <= x) {
            return;
        }
        if (l >= x and r <= y) {
            apply(p, v, r - l);
            return;
        }
        int m = l + r >> 1;
        push(p, r - l);
        Apply(l(p), l, m, x, y, v);
        Apply(r(p), m, r, x, y, v);
        pull(p);
    }
    void Apply(int l, int r, const Tag &v) {
        return Apply(1, 0, n, l, r, v);
    }
};

struct Tag {
    void apply(Tag t) {
    }
};
struct Info {
    int sum = 0;
    int ma = 0 ; 
    void apply(Tag t, int len) {
    }
};
Info operator+(Info a, Info b) {
    Info c;
    c.ma = max (a.ma , b.ma) ; 
    c.sum = a.sum + b.sum ; 
    return c;
}
vector <Info > a (N) ; 
LSGT <Info , Tag > sgt(a) ;

int vis [N] ; 

void dfs (int root ) {
	
	//如果已经把这个区间用小区间更新过值 就跳过
	if (vis[root]) return ; 
	
	//先递归把所有这个区间里的子区间求出最大贡献
	for (auto t : have[root]) {
		dfs (t) ; 
	}
	
	//因为开了个线段树来求区间最大值 所以维护一个修改过的位置
	vi get ; 
	
	//对于所有包含在内的小区间
	for (auto t : have[root]) {
		//如果小区间端点值比大区间的小 那肯定不会更新 
		if (e[t].v < e[root].v) continue ; 
		
		//经典区间合并问题 查询当前区间左端点前面的所有区间的右端点
		int l = e[t].l ; 
		int v = sgt.query(0 , l).ma ;
		
		//每个线段树结点的意思是当前大区间内 最左端到当前结点的区间所能对大区间产生最大的“额外更新”
		//值为前面与当前小区间不相交的其它小区间最大值 + 当前小区间最大贡献（已经递归求出）- 当前小区间长度 * 大区间端点值（也就是大区间原本的贡献）
		int to = v + e[t].w - (e[t].r - e[t].l + 1 )* (e[root].v) ;
		
		//右端点插入线段树
		Info T ;
		T.sum = to ;
		T.ma = to ; 
		sgt.modify (e[t].r - 1, T ) ;
		
		//保存修改过的位置
		get.pb (e[t].r - 1) ;  
	}
	
	//大区间贡献加上包含的小区间中能产生最大贡献的值
	e[root].w += sgt.query (0 , e[root].r ).ma ;
	
	//将用过的线段树位置置零
	for (auto t : get ) {
		Info T ;
		T.sum = 0 ;
		T.ma = 0 ;
		sgt.modify(t , T ) ;  
	}
	
	//打上标记 避免重复更新贡献（因为一个小区间可能被多个大区间包含 ， 可能递归很多次这个小区间 然后小区间又能被小小区间更新最大值 ，所以得标记上以防止重复更新）赛时还wa了我一发
	vis[root] = 1 ; 
	
}

void solve()
{
	int n ;
	cin >> n ;
	vector <int > a (n * 2 + 1) ;
	for (int i = 1 ; i <= 2 * n ; i ++ ) {
		cin >> a[i] ;
	}
	
	vi qian (n + 1) , hou (n + 1) ;
	for (int i = 1 ; i <= 2 * n ; i ++ ) {
		int x = a[i] ;
		if (qian[a[i]] == 0 ) {
			qian[a[i]] = i ; 
		}
		else {
			hou[a[i]] = i ; 
		}
	}
	
	for (int i = 1;  i <= n ; i ++ ) {
		e[i] = {qian[i] , hou[i] ,i ,  i * (hou[i] - qian[i] + 1)} ; 
	}
	
	
	//区间合并模板 按左端点排序枚举，右端点插入
	sort (e + 1,  e + n + 1 , [&](seg a , seg b) {
		return a.l < b.l ; 
	}) ;
	
	//处理区间包含关系 大区间i包含小区间j
	for (int i = 1 ; i <= n ; i ++ ) {
		for (int j = 1 ; j <= n ; j ++ ) {
			if (e[i].l < e[j].l && e[i].r > e[j].r) {
				have[i].pb(j) ; 
				
			}
		}
	}
	
	//要求全局的贡献 也就是在0和2 * n + 1 处加上0 答案就是e[0].w
	for (int i = 1 ; i <= n ; i ++ ) {
		have[0].pb(i) ; 
	}			

	e[0] = {0 , 2 * n + 1 , 0 , 0 } ; 
	dfs(0) ;
	cout << e[0].w << endl ; 

	
}

signed main()
{
	IOS
	cout << fixed << setprecision(2) ; 
	int _ = 1;
	// cin>>_;
	while(_ -- )
	{
		solve();
	}
	return 0;
}


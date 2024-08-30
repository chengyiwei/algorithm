#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

//#define x first
//#define y second
#define DEBUG
#define SEE(a) //cout <<#a<<" : "<<a<< endl;
using namespace std;


const double PI = acos(-1.0);
double eps = 1e-8;
struct Point{
	int x,y;
	Point(){}							          // 无参构造
	Point(double _x,double _y){ x = _x; y = _y; } // 有参构造
	
	Point operator + (const Point b) const{ return Point( x+b.x,y+b.y );}
	Point operator - (const Point b) const{ return Point( x-b.x,y-b.y );}
	Point operator * (const double k) const{ return Point(k*x,k*y);}    // 向量数乘 at = (x*t,y*t)
	Point operator / (const double k) const{ return Point(x/k, y/k);}    // 向量数除 同上
	
	double operator * (const Point b) const{ return x*b.x + y*b.y; }    //重载 点积  a*b = abcosA
	//a.b == 0垂直    a.b == ab平行     夹角(a.b)/ab
	double operator ^ (const Point b) const{ return x*b.y - y*b.x; }    //叉乘   注意加括号 不然优先级很低
	
	bool operator<(const struct Point & that)const{
		return x == that.x ? y < that.y : x < that.x;
	}
};

double abs(Point a){return hypot(a.x,a.y);}      //模长
double dis(Point a,Point b){return hypot(a.x-b.x,a.y-b.y);}       //两点距离
double angle(Point a, Point b){return acos(a*b / abs(a) / abs(b));}   //两点成为两个向量末端 求两向量的夹角
double cross(Point a,Point b,Point c){return (b-a) ^ (c-a);} //叉积   此处为向量(b-a)(c-a)sinA性质如下
//(b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x);   cross(a,b,c) >0:c在直线ab左侧  <0:c在直线ab右侧   =0:三点共线
//有a,b,c,d四个点形成ab直线和cd直线 cross(a,b,c) * cross(a,b,d) >0 无交点 <=0 有交点 =0 有一点在其他线上
//线段ab和cd无交点 (cross(a,b,c)*cross(a,b,d)>0 || cross(c,d,a)*cross(c,d,b) > 0)
//直线ab与线段cd有无交点 cross(a,b,c)*cross(a,b,d)>0

Point getNode(Point a,Point u,Point b,Point v){  //注意u,v是a,b直线的向量
	double t = (a-b) ^ v / (v^u);
	return a + u*t;
}

bool intersect(Point a,Point b,Point c,Point d){    //判断两线段ab,cd相不相交
	if(cross(a,b,c)*cross(a,b,d) > 0 ||
		cross(c,d,a)*cross(c,d,b) > 0) return 0;
	return 1;
}

double sector(Point a,Point b,double R){    //扇形面积   假定圆心为原点
	double angle = acos( (a * b) / abs(a) / abs(b) );  //点积求夹角  返回值为[0,Pi]
	SEE(angle);
	if( (a ^ b) < 0) angle = -angle;        //a叉乘b小于0 说明b在a的顺时针方向  角度出来是大于PI的 所以取反
	double t = R * R * angle / 2;
	return R * R * angle / 2;
}

Point rotate(Point a,double b){     //逆转角  把一个向量逆时针转b度
	return Point(a.x*cos(b) - a.y*sin(b),a.x*sin(b) + a.y*cos(b));
} //a = (x,y) = (lcosa,lsina)   a` = (lcos(a+b),lsin(a+b))  把a`展开即得上式

Point norm(Point a){      //单位向量
	return a / abs(a);
}

bool onSegment(Point p,Point a,Point b){     //p在线段ab上
	return fabs((a-p) ^ (b-p)) < eps && ((a-p) * (b-p)) <= 0;
}


double getDP2(Point a,Point b,Point &pa,Point &pb,double R){  //返回线段ab离圆心的最近距离 以及pa、pb两个与圆的交点
	Point e = getNode(a,b-a,{0,0},rotate(b-a, PI/2));  //求垂足
	double d = abs(e);                               //d为线段ab离圆心的最近距离
	if(!onSegment(e,a,b)) d = min(abs(a),abs(b));       //垂足e不在线段ab上
	if(R <= d) return d;        //如果
	double len = sqrt(R*R - abs(e) * abs(e));
	pa = e + norm(a-b) * len;
	pb = e + norm(b-a) * len;
	return d;
}

double getArea(Point a,Point b,double R){        //面积的交  假设圆心在原点
	if(fabs(a ^ b) < eps) return 0;             //相当于cross({0,0},a,b) == 0 共线
	double da = abs(a),db = abs(b);             //两点与圆心（原点）的距离
	SEE(da) SEE(db)
	if(R >= da && R >= db) return a^b / 2;      //若da和db都小于R 则说明ab在圆内
	Point pa,pb;                                //pa,pb分别为a在圆外、b在圆外时ab与圆的交点
	double d = getDP2(a,b,pa,pb,R);               //d 为ab与圆心的垂直距离
	SEE(pa.x) SEE(pa.y) SEE(pb.x) SEE(pb.y) SEE(d)
	if(R <= d) return sector(a,b,R);            //ab在圆外
	if(R >= da) return (a^pb)/2 + sector(pb,b,R);   //a在圆外 pb为ab与圆的交点  一块三角形+一块扇形
	if(R >= db) return sector(a,pa,R) + (pa^b)/2;   //b在圆外 pa为ab与圆的交点
	return sector(a,pa,R) + (pa^pb)/2 + sector(pb,b,R);   //ab都在圆外
}

vector<Point> Andrew(vector<Point>& a){        //返回凸包周长
	sort(a.begin(),a.end());
	int n = a.size();
	vector<Point>que;
	for(int i = 0;i < n;++i){		//下凸包
		while(que.size() > 1 && cross(que[que.size() - 2],que[que.size() - 1],a[i]) <= 0) que.pop_back();
		que.push_back(a[i]);      //如果 <= 0 说明后来的点在该线右侧或共线 则que.top被包括其中 所以pop掉
	}
	
	int ht = que.size();
	for(int i = n - 2;i >= 0;--i){	//上凸包
		while(que.size() > ht && cross(que[que.size() - 2],que[que.size() - 1],a[i]) <= 0) que.pop_back();
		que.push_back(a[i]);
	}
	
	double res = 0;		//周长放这里
	for(int i = 0;i < que.size() - 1;++i)res += dis(que[i],que[i + 1]);
//    return res;           //返回凸包周长
	return que;           //返回凸包数组
}

int get_dis(Point a,Point b){
	return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}
int rotating_calipers(vector<Point>& s){       //旋转卡壳 返回凸包最长直径  s为跑了Andrew后的凸包数组
	int res = 0;
	for(int i = 0,j = 1;i < s.size() - 1;++i){
		while(cross(s[i],s[i + 1],s[j]) < cross(s[i],s[i + 1],s[j + 1])) j = (j + 1) % (s.size() - 1);
		res = max(res,max((s[i].x-s[j].x) * (s[i].x-s[j].x) + (s[i].y-s[j].y) * (s[i].y-s[j].y),
			(s[i + 1].x-s[j].x) * (s[i + 1].x-s[j].x) + (s[i + 1].y-s[j].y) * (s[i + 1].y-s[j].y)));
	}
	return res;
}


void solve() {
	int n;cin >> n;
	vector<Point>dat(n);
	for(int i = 0;i < n;++i) cin >> dat[i].x >> dat[i].y;

	vector<Point>s = Andrew(dat);
	cout << rotating_calipers(s) << endl;
}

int main(){
    freopen ("in.in", "r", stdin);
    freopen ("out0.out", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int _ = 1;
//    cin >> _;
	while(_ --){
		solve();
	}
	
}

/*
  3
  TCC
 */
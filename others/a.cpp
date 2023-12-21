#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int brand(){return (rand()<<15)|rand();}
//st 学生名单 
vector<string> st = {"神秘选手1号","神秘选手2号","陈皓轩", "程义威", "丁烨希", "方奕俊", "郭宇杰", "蓝玉婷", "李家诚", "李洋", "李之豪", "李志宇", "林立仁", "林谦", "刘爱平", "罗海波", "罗豪", "彭灿", "沈锐", "谭佳燕", "王立为", "肖薛林", "颜琪翊加", "张宇", "赵星如", "赵紫瑜", "周星同"};
//black 黑名单 
vector<string> black ={"神秘选手1号","神秘选手2号"};

int main(){
    srand(time(0));
    int now=brand()%st.size();
    while(find(black.begin(),black.end(),st[now])!=black.end())
        now=brand()%st.size();
    printf("%s",st[now].c_str());
    return 0;
}
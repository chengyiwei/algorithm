#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int get_(int L,int R,vector<int>& p){ //查询 p数组中 [L,R] 范围内数字的个数
    int l = lower_bound(p.begin(),p.end(),L) - p.begin();
    int r = upper_bound(p.begin(),p.end(),R) - p.begin();
    return r-l;
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F0.out","w",stdout);
    n=read(),m=read(),k=read();
    int now_ans = 0, num_bottom = 0;
    vector<int> col(2*n+1);
    vector<int> fst(n+1,0); //每种颜色第一个没有被装入盒子的位置
    vector<vector<int> > p(n+1,vector<int>()); //记录每个颜色的位置
    set<int> st; //每种颜色没有加入盒子的最早的位置
    vector<deque<int> >mp(n+1,deque<int>()); //每种颜色占据的盒子里面装球的个数

    for(int i=1;i<=n;i++)
        col[i] = col[i+n] = read();
    for(int i=1;i<=2*n;i++)
        p[col[i]].push_back(i);
    for(int i=1;i<=n;i++){
        if(mp[col[i]].size() > 0 && mp[col[i]].back() < k) //说明还能装
            mp[col[i]].back()++, now_ans++;
        else if(num_bottom < m) // 还有空的盒子
            mp[col[i]].push_back(1), num_bottom++, now_ans++;
        else if(fst[col[i]] == 0) //没有空的盒子可放了
            fst[col[i]] = i, st.insert(i);
    }

    for(int i=1;i<=n;i++){
        printf("%d\n",now_ans);
        if(st.empty()) continue; //没有可以丢掉的球
        int pos = *st.begin(); //pos 位置为待选球
        int l = upper_bound(p[col[i]].begin(),p[col[i]].end(),i) - p[col[i]].begin(); //找到 i 后面那个颜色相同的 在 p[col[i]] 中的位置
        int r = lower_bound(p[col[i]].begin(),p[col[i]].end(),pos) - p[col[i]].begin(); //找到 pos 前面那个颜色相同的 在 p[col[i]] 中的位置
        int sum = r-l; //[i+1,pos] 里面和 i 颜色相同的球的个数
        // int sum = get_(i+1,pos,p[col[i]]); if(sum < 0) sum = 0;
        if(sum % k == 0){ //pos 位置的球需要被放到盒子里面
            now_ans -= mp[col[i]].back(); mp[col[i]].pop_back(); //把 col[i] 最后一个盒子里面的球拿出来
            int cnt = mp[col[i]].size() * k; //盒子里面一共装了 cnt 个颜色为 col[i] 的球
            int t = upper_bound(p[col[i]].begin(),p[col[i]].end(),i) - p[col[i]].begin(); //找到 i 后面那个颜色相同的 在 p[col[i]] 中的位置
            if(fst[col[i]])
                st.erase(fst[col[i]]); //删除之前的 fst[col[i]]
            fst[col[i]] = p[col[i]][t + cnt]; st.insert(fst[col[i]]); //更新 fst[col[i]] 

            int sum_t = get_(pos,i+n,p[col[pos]]); //[pos,i+n] 里面和 col[pos] 颜色相同的球的个数
            if(sum_t <= k){ //能全部放进盒子
                now_ans += sum_t;
                st.erase(fst[col[pos]]); fst[col[pos]] = 0;
                mp[col[pos]].push_back(sum_t);
            }
            else{ //不能全部放进盒子
                now_ans += k;
                st.erase(fst[col[pos]]);
                int t = lower_bound(p[col[pos]].begin(),p[col[pos]].end(),pos) - p[col[pos]].begin();
                fst[col[pos]] = p[col[pos]][t + k]; st.insert(fst[col[pos]]);
                mp[col[pos]].push_back(k);
            }
        }
        else if(fst[col[i]]){  //更新 f[col[i]]
            int cnt = mp[col[i]].size() * k;
            int t = upper_bound(p[col[i]].begin(),p[col[i]].end(),i) - p[col[i]].begin();
            st.erase(fst[col[i]]);
            fst[col[i]] = p[col[i]][t + cnt];
            st.insert(fst[col[i]]);
        }
    }
    return 0;
}
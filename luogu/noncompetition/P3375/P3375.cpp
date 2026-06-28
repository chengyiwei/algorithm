#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<int> build_next(string p){
    int len_p=p.length(),j=0;
    vector<int> nxt(len_p+1);
    int t=nxt[0]=-1;
    while(j<len_p){
        if(0>t||p[j]==p[t])
            j++,t++,nxt[j]=t;
        else
            t=nxt[t];
    }
    return nxt;
}
int match(string s,string p)
{
    vector<int> nxt=build_next(p);
    int len_s=s.length(),len_p=p.length();
    int i=0,j=0;
    while(j<len_p&&i<len_s){
        if(0>j||s[i]==p[j]){ // 若匹配，或 p 已移出最左侧（两个判断的次序不可交换）
            i++,j++;
            if(j==len_p){ // 匹配成功，记录位置 同时 j = Next[j] 以便继续匹配
                ans.push_back(i-j+1);
                j=nxt[j];
            }
        }
        else
            j=nxt[j];
    }
    return i-j;
}

int main(){
    freopen("P3375.in","r",stdin);
    string s,p;
    cin>>s>>p;
    match(s,p);
    for(auto x:ans)
        cout<<x<<endl;
    vector<int> border=build_next(p);
    for(int i=1;i<border.size();i++)
        cout<< border[i] << " ";
    return 0;
}
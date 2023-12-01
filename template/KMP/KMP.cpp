#include<bits/stdc++.h>
using namespace std;
vector<int> build_next(string p){
    int len_p=p.length(),j=0;
    vector<int> nxt(len_p);
    int t=nxt[0]=-1;
    while(j<len_p-1){
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
        if(0>j||s[i]==p[j]) // 若匹配，或 p 已移出最左侧（两个判断的次序不可交换）
            i++,j--;
        else
            j=nxt[j];
    }
    return i-j;
}

int main(){
    freopen("KMP.in","r",stdin);
}
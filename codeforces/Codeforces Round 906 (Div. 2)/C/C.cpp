#include<bits/stdc++.h>
using namespace std;

int T,N;
string s,p="01";

vector<int> ans;
void check(string a){
    int Le=0,Ri=N-1;
    while(Le<=Ri){
        if(a[Le]!=a[Ri]) Le++,Ri--;
        else if(a[Le]=='0'){
            a.insert(Ri+1,p);
            ans.push_back(Ri+1);
            Ri+=2;
        } 
        else {
            a.insert(Le+1-1,p);
            ans.push_back(Le+1-1);
            Ri+=2;
        }
    }
    int Len=ans.size();
    if(Len>300){printf("-1\n");return ;}
    printf("%d\n",Len);
    for(int i=0;i<Len;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return;
}
void solve(){
    int num_0=0;ans.clear();
    for(int i=0;i<N;i++) num_0+=s[i]=='0';
    if(num_0*2!=N) {printf("-1\n");return;}
    check(s);
}

int main(){
    // freopen("C.in","r",stdin);
    cin>>T;
    while(T--){
        cin>>N>>s;
        solve();
    }
    return 0;
}
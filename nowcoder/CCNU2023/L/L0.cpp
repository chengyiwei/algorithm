#include<bits/stdc++.h>
using namespace std;
struct Bit{
    int x,id;
    bool b[31];
    void get_bit(){
        for(int i=0;i<31;i++) b[i]=x>>i&1;
    }
    bool operator <(const Bit &t) const {return id<t.id;}
};
set<Bit> p;
int n;
int main(){
    freopen("L.in","r",stdin);
    int pos=30;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        Bit t;t.x=x;t.id=i;t.get_bit();
        p.insert(t);
    }
    while(pos>=0){
        int sum_now=0;
        for(auto& x:p)
            sum_now+=x.b[pos];
        if(sum_now<2) {pos--;continue;}
        for(auto it=p.begin();it!=p.end();){
            if(it->b[pos]==0)
                it=p.erase(it);
            else
                ++it;
        }
        pos--;
    }
    auto it=p.begin();
    cout<<it->id<<" ";cout<<(++it)->id<<endl;
    return 0;
}
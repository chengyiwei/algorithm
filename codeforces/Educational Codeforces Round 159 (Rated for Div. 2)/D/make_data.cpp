#include <bits/stdc++.h>
using namespace std;

const int N=2e5;

int main() {
    freopen("D.in","w",stdout);
    string s="RR",p="RL";
    while(s.size()<N)s+=p;
    s.pop_back();
    s+="R";
    cout<<N<<" "<<N<<"\n"<<s<<"\n";
    for(int i=0;i<N;i++){
        if(i)cout<<"\n";
        cout<<"2 0 1 "<<N;
    }
    cout<<endl;

}

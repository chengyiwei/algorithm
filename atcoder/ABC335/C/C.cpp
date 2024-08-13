#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    node(int x,int y):x(x),y(y){}
};
int main(){
    freopen("C.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    deque<node> q;
    for(int i=1;i<=n;i++)q.push_back(node(i,0));
    while(m--){
        int op;cin>>op;
        if(op==1){
            char ch;cin>>ch;
            node tmp=q.front();q.pop_back();
            if(ch=='U'){
                tmp.y++;
            }
            else if(ch=='D'){
                tmp.y--;
            }
            else if(ch=='L'){
                tmp.x--;
            }
            else if(ch=='R'){
                tmp.x++;
            }
            q.push_front(tmp);
        }
        else{
            int x;cin>>x;x--;
            cout<<q[x].x<<" "<<q[x].y<<endl;
        }
    }
    return 0;
}
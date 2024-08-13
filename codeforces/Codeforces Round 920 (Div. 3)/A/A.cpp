#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x_1,x_2,x_3,x_4,y_1,y_2,y_3,y_4;
    scanf("%d%d",&x_1,&y_1);
    scanf("%d%d",&x_2,&y_2);
    scanf("%d%d",&x_3,&y_3);
    scanf("%d%d",&x_4,&y_4);
    int min_x=min(min(x_1,x_2),min(x_3,x_4));
    int max_x=max(max(x_1,x_2),max(x_3,x_4));
    int min_y=min(min(y_1,y_2),min(y_3,y_4));
    int max_y=max(max(y_1,y_2),max(y_3,y_4));
    int S=(max_x-min_x)*(max_y-min_y);
    printf("%d\n",S);
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        solve();
    }
}
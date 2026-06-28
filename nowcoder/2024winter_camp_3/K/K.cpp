#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool check(int a, int b){
    if(a % 2 == 0) return 0;
    if(b % 2 == 1) return 0;
    if(a * 2 < b) return 0;
    if(b * 2 < a - 1) return 0;
    return 1;
}

void solve(){
    int a, b; scanf("%d%d", &a, &b);
    if(!check(a, b)){
        printf("No\n");
        return ;
    }
    vector<pii> ans(a + b + 1, pii(-1, -1));
    stack<int> now_a, now_b, free_a, free_b; // a 是黑色，b 是白色
    for (int i = 2; i <= a; i++)
        now_a.push(i);
    for (int i = a + 1; i <= a + b; i++)
        now_b.push(i);
    free_a.push(1);
    while(!now_a.empty() || !now_b.empty()){
        if(!free_a.empty()){
            if(!now_b.empty()){
                int x1 = now_b.top(); now_b.pop();
                int x2 = now_b.top(); now_b.pop();
                ans[free_a.top()] = pii(x1, x2); free_a.pop();
                free_b.push(x1); free_b.push(x2);
            }
        }
        if(!free_b.empty()){
            if(!now_a.empty()){
                int x1 = now_a.top(); now_a.pop(); 
                int x2 = now_a.top(); now_a.pop();
                ans[free_b.top()] = pii(x1, x2); free_b.pop();
                free_a.push(x1); free_a.push(x2);
            }
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= a + b; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen ("K.in", "r", stdin);
    freopen ("K.out", "w", stdout);
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}
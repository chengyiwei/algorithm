#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 505 + 5;
ll Tex, n, m;
int a[MAXN][MAXN], b[MAXN][MAXN];
void AC(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%1d",&b[i][j]);
        }
    }
    for(int i = 1; i < n; i ++){
        for(int j = 1; j < m; j ++){
            if(((a[i][j] + 1) % 3) == b[i][j]){
                a[i][j] = (a[i][j] + 1) % 3; 
                a[i][j + 1] = (a[i][j + 1] + 2) % 3; 
                a[i + 1][j] = (a[i + 1][j] + 2) % 3; 
                a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3; 
            }
            else if((a[i][j] + 2) % 3 == b[i][j]){
                a[i][j] = (a[i][j] + 2) % 3; 
                a[i][j + 1] = (a[i][j + 1] + 1) % 3; 
                a[i + 1][j] = (a[i + 1][j] + 1) % 3; 
                a[i + 1][j + 1] = (a[i + 1][j + 1] + 2) % 3; 
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i][j] == b[i][j]) continue;
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}
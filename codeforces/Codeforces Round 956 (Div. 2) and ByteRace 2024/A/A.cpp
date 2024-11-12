#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n;
void AC(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cout << i << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}
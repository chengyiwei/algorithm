#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex;
double a, b, r;
void AC(){
    cin >> a >> b >> r;
    if(b <= r){
        printf("%.2lf\n", 2 * a - r);
    }
    else{
        printf("%.2lf\n", 2 * sqrt(a * a + (b - r) * (b - r)) - r);
    }
}
int main(){
    // ios::sync_with_stdio(false);
    ll cnt = 1;
    cin >> Tex;
    while(Tex --){
        cout << "Case #" << cnt ++ << ": ";
        AC();
    }
    return 0;
}
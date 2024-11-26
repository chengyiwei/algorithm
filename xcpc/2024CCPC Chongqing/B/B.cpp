#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex;
long double ppmax, a, b, c, d, e, f, Acc, pp;
void AC(){
    scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf", &ppmax, &a, &b, &c, &d, &e, &f);
    Acc = (300 * a + 300 * b + 200 * c + 100 * d + 50 * e) / (300 * (a + b + c + d + e + f)) * 100;
    pp = max(0.0L, (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) / (320 * (a + b + c + d + e + f)) - 0.8) * 5 * ppmax;
    // printf("%Lf\n", Acc); Acc = 12.235;
    printf("%.2Lf%% %lld\n", (long double)(((ll)((Acc * 1000 + 5.000000001) / 10)) / 100.0L), ((ll)((pp * 10 + 5.000000001) / 10)));
}
int main(){
    // freopen("B.in", "r", stdin);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}
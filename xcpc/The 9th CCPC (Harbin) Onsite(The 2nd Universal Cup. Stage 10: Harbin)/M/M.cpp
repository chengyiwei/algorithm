#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    string id;
    ll x1, y1, x2, y2, r;
    char ch;
};
ll n;
vector<node> a;
bool check1(ll x, ll y, ll r, ll x0, ll y0){
    return (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) <= r * r;
}
bool check2(ll x1, ll y1, ll x2, ll y2, ll x0, ll y0){
    return (x1 <= x0) && (x0 <= x2) && (y1 <= y0) && (y0 <= y2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        string opt;
        ll x1, y1, x2, y2, r;
        char ch;
        cin >> opt;
        if(opt == "Circle"){
            cin >> x1 >> y1 >> r >> ch;
            a.push_back({opt, x1, y1, 0, 0, r, ch});
        }
        else if(opt == "Rectangle"){
            cin >> x1 >> y1 >> x2 >> y2 >> ch;
            a.push_back({opt, x1, y1, x2, y2, 0, ch});
        }
        else{
            cin >> x1 >> y1 >> x2 >> y2; 
            for(int j = y2; j >= y1; j --){
                for(int i = x1; i <= x2; i ++){
                    // cout << i << " " << j << "\n";
                    char ans = '.';
                    for(int k = a.size() - 1; k >= 0; k --){
                        if(a[k].id == "Circle"){
                            if(check1(a[k].x1, a[k].y1, a[k].r, i, j)){
                                ans = a[k].ch;
                                break;
                            }
                        }
                        else{
                            if(check2(a[k].x1, a[k].y1, a[k].x2, a[k].y2, i, j)){
                                ans = a[k].ch;
                                break;
                            }
                        }
                    }
                    cout << ans;
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
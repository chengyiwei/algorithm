#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n, a[MAXN];
void AC(){
    cin >> n;
    ll cnt = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] < a[i - 1]) cnt ++;
    }
    if(cnt == 0){
        cout << "Yes" << endl;
    }
    else if(cnt == 1){
        if(a[1] >= a[n]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        cout << "No" << endl;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}
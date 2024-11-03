#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, m;
void AC(){
    cin >> m;
    ll x = 0, y = 0, cnt = 0;
    char ch;
    for(int i = 1; i <= m; i ++){
        cin >> ch >> cnt;
        if(ch == 'S') y -= cnt;
        else if(ch == 'N') y += cnt;
        else if(ch == 'E') x += cnt;
        else x -= cnt;  
    }

    if(x == 0 && y == 0){
        cout << 7 << " " << 'E' << "\n";
        cout << 'Z' << " " << 1 << "\n";
        cout << "L" << "\n";
        cout << 'Z' << " " << 1 << "\n";
        cout << "L" << "\n";
        cout << 'Z' << " " << 1 << "\n";
        cout << "L" << "\n";
        cout << 'Z' << " " << 1 << "\n";
        return;
    }

    if(y == 0){
        if(x > 0){
            cout << 1 << " " << 'E' << "\n";
            cout << 'Z' << " " << x << "\n";
        }
        else{
            cout << 1 << " " << 'W' << "\n";
            cout << 'Z' << " " << -x << "\n";
        }
        return;
    }

    if(x == 0){
        if(y > 0){
            cout << 1 << " " << 'N' << "\n";
            cout << 'Z' << " " << y << "\n";
        }
        else{
            cout << 1 << " " << 'S' << "\n";
            cout << 'Z' << " " << -y << "\n";
        }
        return;
    }

    if(x > 0){
        cout << 3 << " " << 'E' << "\n";
        cout << 'Z' << " " << x << "\n";
        if(y > 0){
            cout << 'L' << "\n";
            cout << 'Z' << " " << y << "\n";
        }
        else{
            cout << 'R' << '\n';
            cout << 'Z' << " " << -y << "\n";
        }
    }
    else{
        cout << 3 << " " << 'W' << "\n";
        cout << 'Z' << " " << -x << "\n";
        if(y > 0){
            cout << 'R' << "\n";
            cout << 'Z' << " " << y << "\n";
        }
        else{
            cout << 'L' << '\n';
            cout << 'Z' << " " << -y << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}
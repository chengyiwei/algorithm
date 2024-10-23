#include<bits/stdc++.h>
using namespace std;
int Tex;
string s;
void AC(){
    cin >> s;
    int top = 0;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '(') top ++;
        else if(top) top --;
    }
    if(top) cout << "impossible" << "\n";
    else cout << s << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}
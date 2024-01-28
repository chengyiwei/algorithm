#include<bits/stdc++.h>
using namespace std;
int mp[30];
int main(){
    string s;cin>>s;
    for(auto e:s) mp[e-'a']++;
    int max_x=0;
    char ch;
    for(int i=0;i<26;i++)
        if(max_x < mp[i]){
            max_x = mp[i];
            ch = 'a'+i;
        }
    cout<<ch<<endl;
    return 0;
}
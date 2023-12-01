#include<bits/stdc++.h>
using namespace std;
int match(string s,string p)
{
    int lens=s.length(),lenp=p.length(),i=0,j=0;
    for(i=0;i<lens-lenp+1;i++){
        for(j=0;j<lenp;j++)
            if(p[i+j]!=s[j])
                break;
        if(j>=lenp)
            break; //找到匹配子串
    }
    return i;
}
int main(){
    freopen("KMP.in","r",stdin);

}
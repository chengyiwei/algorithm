#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;

int a[maxn];
char s[maxn];
int main(){
    int n;
    
    scanf("%d",&n);
    n = n * 2 + 2;;
    for(int i = 0;i < n ;i ++){
        scanf("%d",&a[i]);
    }
    for(int i = 0 ;i < n ;i ++){
         if(i % 2)
             s[i] = '|';
         else 
             s[i] = 'b';
    }
    s[0] = '&';
    int o = 0;
    for(int i = 1, r = 1;i < n ;i ++){
         
         a[i] --;
         int k = i + a[i];
         if(k <= r ) continue;
         if(!o)
            s[i] = 'a';
         o = 1;
         int cnt = 1;
         while(a[i] >= cnt&&  i + cnt < n && i - cnt > 0) {

            int p = a[i+cnt] - 1 + i + cnt;
            s[i + cnt] = s[i - cnt],cnt++;
            if(p > i + a[i])
              break;
        }
         r = i + a[i];
         i = cnt + i - 2;

    }
    for(int i = 1;i < n ;i ++)
      if(i % 2 == 0)
        putchar(s[i]);

    return 0;
}
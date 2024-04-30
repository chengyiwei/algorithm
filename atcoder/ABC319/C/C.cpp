#include<bits/stdc++.h>
using namespace std;
int a[15], order[15], id[15],ans;
int line[][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 5, 9}, {3, 5, 7}};
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret;
}
bool check_2(int x,int y,int z){
    if(a[x]==a[y] && (id[z]>id[x]&&id[z]>id[y]))
        return 0;
    if(a[x]==a[z] && (id[y]>id[x]&&id[y]>id[z]))
        return 0;
    if(a[y]==a[z] && (id[x]>id[y]&&id[x]>id[z]))
        return 0;
    return 1;
}
bool check(){
    int ret = 0;
    for (int k = 0; k < 8;k++)
        if(!check_2(line[k][0],line[k][1],line[k][2]))
            return 0;
    return 1;
}
int main(){
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    for (int i = 1; i <= 9;i++)
        a[i] = read(), order[i] = i;
    do{
        for (int i = 1; i <= 9;i++)
            id[order[i]] = i;
        ans += check();
    } while (next_permutation(order + 1, order + 10));
    printf("%.15f", ans / 362880.0);
    return 0;
}
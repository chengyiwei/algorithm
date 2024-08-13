#include<bits/stdc++.h>
using namespace std;
int mp[105][12];
int F[105][200][200];
int n,m;
int sta[200];

int init_line(int n){
    int M = 0;
    for(int i = 0; i < n; i++)
        if( (i & (i >> 2)) == 0 && (i & (i << 2)) == 0)
            sta[M++] = i;
    return M;
}

int count_line(int i, int x){
    int sum = 0;
    for(int j = m - 1; j >= 0; j--){
        if(x & 1)
            sum += mp[i][j];
        x >>= 1;
    }
    return sum;
}

int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        int M = init_line(1 << m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&mp[i][j]);
        int ans = 0;
        memset(F,0,sizeof(F));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < M; k++){
                    if(i == 0){
                        F[i][j][k] = count_line(i,sta[j]);
                        ans = max(ans, F[i][j][k]);
                        continue;
                    }
                    if( (sta[j] & (sta[k] >> 1)) || (sta[j] & (sta[k] << 1)) )
                        continue;
                    int tmp = 0;
                    for(int p = 0; p < M; p++){
                        if( (sta[p] & (sta[k] >> 1)) || (sta[p] & (sta[k] << 1)) )
                            continue;
                        if( sta[j] & sta[p])
                            continue;
                        tmp = max(tmp, F[i-1][k][p]);
                    }
                    F[i][j][k] = tmp + count_line(i,sta[j]);
                    ans = max(ans, F[i][j][k]);
                }
        printf("%d\n",ans);
    }
    return 0;
}
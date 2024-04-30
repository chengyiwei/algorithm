#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
	return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
	freopen("D.in","w",stdout);
	srand(GetTickCount());
	int N=brand()%100+1,M=brand()%N+1;
	printf("%d %d\n",N,M);
	for(int i=1;i<=N;i++)
		printf("%d ",brand()%100+1);
	printf("\n");
	for(int i=1;i<=M;i++)
		printf("%d ",brand()%100+1);
}

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	freopen("E.in","w",stdout);
	srand(GetTickCount());
	int N=100000;
	printf("%d\n",N);
	for(int i=1;i<=N;i++){
		int x=rand()%101;
		if(rand()&1)x=-x;
		printf("%d ",x);
	}
}

#include<bits/stdc++.h>
#include<ctime>
using namespace std;
const int maxn=1e5+5;
double a[maxn],sum=0;
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>a[i],sum+=a[i];
	double b=sum/(N+1);
	double a=2*b;
	for(int i=1;i<=N;i++){
		printf("%.15lf ",i==1?a:b);
	} 
	return 0;
} 

#include<iostream>
#include<ctime>
using namespace std;
bool prime(int n);
int reverse(int n);
int main()
{
	int i,n,num;
	cout<<"2023114400王珏";
	cout<<"请输入数据个数：";
	cin>>n;
	cout<<"随机产生的"<<n<<"个数中的可逆素数有："<<endl;
	srand(time(NULL));
	for(i=1;i<=n;i++)
	{
		num=10+rand()%(500-10+1);
		if(prime(num)&&prime(reverse(num)))       //嵌套调用子函数
			cout<<num<<endl; 
	}
	return 0;
}
bool prime(int n)                                 //子函数实现素数判定
{
	bool f=1;
	int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			f=0;
			break;
		}
	}
	return f;
}
int reverse(int n)                                    //子函数实现求反序数
{
	int i,num=0;
	while(n>0)
	{
		num=num*10+n%10;
		n/=10;
	}
	return num;
}
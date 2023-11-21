#include<stdio.h>
char a[51][4]={
	//0
	"XXX",
	"X.X",
	"X.X",
	"X.X",
	"XXX", 
	//1
	"..X",
	"..X",
	"..X",
	"..X",
	"..X",
	//2
	"XXX",
	"..X",
	"XXX",
	"X..",
	"XXX",
	//3
	"XXX",
	"..X",
	"XXX",
	"..X",
	"XXX",
	//4
	"X.X",
	"X.X",
	"XXX",
	"..X",
	"..X",
	//5
	"XXX",
	"X..",
	"XXX",
	"..X",
	"XXX",
	//6
	"XXX",
	"X..",
	"XXX",
	"X.X",
	"XXX",
	//7
	"XXX",
	"..X",
	"..X",
	"..X",
	"..X",
	//8
	"XXX",
	"X.X",
	"XXX",
	"X.X",
	"XXX",
	//9
	"XXX",
	"X.X",
	"XXX",
	"..X",
	"XXX"
};

int main() {
    freopen("P5730.in","r",stdin);
    freopen("P5730.out","w",stdout);
	int n;
	scanf("%d\n",&n);
	char ch[n+1];
	scanf("%s",ch);
	
	for(int i=0;i<n;i++){
		int d=ch[i]-48;
		if(i!=n-1)
		    printf("%s.",a[0+5*d]);
		else
		    printf("%s",a[0+5*d]);
		
	}
	printf("\n");
	
	for(int i=0;i<n;i++){
		int d=ch[i]-48;
		if(i!=n-1)
		    printf("%s.",a[1+5*d]);
		else
		    printf("%s",a[1+5*d]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++){
		int d=ch[i]-48;
		if(i!=n-1)
		    printf("%s.",a[2+5*d]);
		else
		    printf("%s",a[2+5*d]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++){
		int d=ch[i]-48;
		if(i!=n-1)
		    printf("%s.",a[3+5*d]);
		else
		    printf("%s",a[3+5*d]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++){
		int d=ch[i]-48;
		if(i!=n-1)
		    printf("%s.",a[4+5*d]);
		else
		    printf("%s",a[4+5*d]);
	}
	
	
}
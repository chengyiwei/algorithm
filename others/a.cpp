#include<stdio.h>
int main(){
    int n,m;
    scanf("%d\n",&n);
    int b[n][2];
    char a[n][17];
    for(int i=0;i<n;i++){
        for(int j=0;j<16;j++){
        	scanf("%c",&a[i][j]);
		}
		scanf("%d %d\n",&b[i][0],&b[i][1]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
    	int t;
    	scanf("%d",&t);
    	for(int j=0;j<n;j++){
    		if(b[j][0]==t){
    			for(int k=0;k<16;k++){
    				printf("%c",a[j][k]);
				}
				printf(" %d\n",b[j][1]);
			}
		}
	}
}
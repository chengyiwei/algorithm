#include<stdio.h>
#include<string.h>
int main()
{
    char a[100]="";
    int i,count=0;
    gets(a);
    for(i=0;a[i+1]!='\0';i++)
    {
        if((a[i]!=' '&&a[i+1]==' ')||(a[i]!=' '&&a[i+1]=='\n'))
            count++;
    }
    printf("%d",count);
    return 0;
}
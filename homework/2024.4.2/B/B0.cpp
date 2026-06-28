#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct
{
    int *data;
    int length;
    int capacity;
}SqList;
void InitList(SqList*L,int capacity)
{
    L->data=(int*)malloc(capacity*sizeof(int));
    if(!L->data){
        exit(1);
        L->length=0;
        L->capacity=capacity;
    }
}
void FreeList(SqList*L) {
    {
    free(L->data);
    L->data=NULL;
    L->length=0;
    L->capacity=0;
    }
}
int ListInsert(SqList*L,int elem)
{
    if(L->length>=L->capacity)
    {
        return 0;
    }
    if((L->length>0)&&(L->data[L->length-1]>=elem))
    {
        return 0;
    }
    L->data[L->length]=elem;
    L->length++;
    return 1;
}
void PrintList(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d",L.data[i]);
    }
    printf("\n");
}
SqList* MergeList(SqList LA,SqList LB)
{
    SqList* LC=(SqList*)malloc(sizeof(SqList));
     int totalLength=LA.length+LB.length;
    LC->data=(int*)malloc(totalLength*sizeof(int));
    if(!LC->data){
        exit(1);
    }LC->length=0;
    LC->capacity=totalLength;
    int i=0,j=0;
    while(i<LA.length&&j<LB.length){
        if(LA.data[i]<=LB.data[j]){
            LC->data[LC->length++]=LA.data[i++];
            }
        else{
            LC->data[LC->length++]=LB.data[j++];
        }
    }
    while(i<LA.length){
        LC->data[LC->length++]=LA.data[i++];
    }
    while(j<LB.length){
        LC->data[LC->length++]=LB.data[j++];
    }
    return LC;
}
int main()
{
    SqList LA,LB,LC;
    int n,elem;
    scanf("%d",&n);
    InitList(&LA,n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&elem);
        while(!ListInsert(&LA,elem)){
            printf("错误:输入的值不满足是非递减条件,请重新输入:");
            scanf("%d",&elem);
        }
    }
    printf("请输入LB的元素个数:");
    scanf("%d",&n);
    InitList(&LB,n);
    for(int i=0;i<n;i++)
    {
        printf("请输入LB的第%d个元素:",i+1);
        scanf("%d",&elem);
        while(!ListInsert(&LB,elem)){
            printf("错误:输入的值不满足是非递减条件,请重新输入:");
            scanf("%d",&elem);
        }
    }
    printf("LA:");
    PrintList(LA);
    printf("LB:");
    PrintList(LB);
}
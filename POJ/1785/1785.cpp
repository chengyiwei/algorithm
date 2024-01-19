#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
const int INF = 2e9;
const int maxn = 1e5 +7;
struct Node{
    char s[115];
    int ls,rs,pri;
}t[maxn];

int n;

void build(){
    stack<int> st; st.push(0); //t[0].pri = INF;
    for(int i=1;i<=n;i++){
        int pos=st.top();
        while(!st.empty() && t[pos].pri < t[i].pri){ // 如果栈顶元素的优先级比当前元素的优先级小，那么就一直往上找，直到找到一个优先级比当前元素大的元素
            st.pop();
            pos = st.top();
        }
        t[i].ls = t[pos].rs;
        t[pos].rs = i;
        st.push(i);
    }
}

void inorder(int x){
    if(x == 0) return;
    printf("(");inorder(t[x].ls);
    printf("%s/%d",t[x].s,t[x].pri);
    inorder(t[x].rs);printf(")");
}

bool cmp(Node a,Node b){
    return strcmp(a.s,b.s) < 0;
}

int main(){
    freopen("1785.in","r",stdin);
    freopen("1785.out","w",stdout);
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=1;i<=n;i++){
            t[i].ls=t[i].rs=0;
            scanf(" %[^/]/%d",t[i].s,&t[i].pri);
        }
        t[0].ls=t[0].rs=0; t[0].pri = INF;
        sort(t+1,t+n+1,cmp);
        build();
        inorder(t[0].rs);
        printf("\n");
    }
    return 0;
}
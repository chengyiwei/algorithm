#include <bits/stdc++.h>
using namespace std;
#define Status int

#define MAXSIZE 10
typedef struct {
    int *elem;
    int len;
} Sqlist;

void init_sqlist(Sqlist &L) {
    L.elem = new int[MAXSIZE];
    L.len = 0;
    return ;
}

void vector_to_list(Sqlist &L, vector<int> &a) {
    for (int i = 0; i < a.size(); i++)
        L.elem[i] = a[i];
    L.len = a.size();
    return ;
}

Status insert_list (Sqlist &L, int pos, int val) {
    if (pos < 0 || pos > L.len + 1) return 0;
    if (L.len == 10) return -1;
    for (int i = L.len - 1; i >= pos - 1; i--) 
        L.elem[i + 1] = L.elem[i];
    L.elem[pos - 1] = val;
    L.len += 1;
    return 1;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
    Sqlist L;
    init_sqlist(L);
    vector_to_list(L, a);

    printf("Before:(");
    for (int i = 0; i < a.size(); i++) {
        if (i != 0)
            printf(",");
        printf("%d",a[i]);
    }
    printf(")\n");
    
    int pos, val; cin >> pos >> val;
    int op = insert_list(L, pos ,val);
    if (op == 0) 
        return cout << "Insert position error!" << endl, 0;
    if (op == -1)
        return cout << "OVERFLOW!" << endl, 0;

    printf("After:(");
    for (int i = 0; i < L.len; i++) {
        if (i != 0)
                printf(",");
        printf("%d", L.elem[i]);
    }
    printf(")");
}
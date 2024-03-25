#include <bits/stdc++.h>

#define MAXSIZE 100
#define OVERFLOW -2
#define ERROR 0
#define OK 1

using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *elem;
	int length;
}SqList;

Status InitList (SqList &L) {
	L.elem = new ElemType[MAXSIZE];
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status GetElem (SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return ERROR;
    e = L.elem[i - 1];
    return OK;
}

int LocateElem (SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e) return i + 1;
    return 0;
}

Status ListInsert (SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return ERROR;
    if (L.length >= MAXSIZE) return ERROR;
    for (int j = L.length; j >= i; j--)
        L.elem[j] = L.elem[j - 1];
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

int GetLength (SqList L) {
    return L.length;
}

Status ListDelete (SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return ERROR;
    e = L.elem[i - 1];
    for (int j = i; j < L.length; j++)
        L.elem[j - 1] = L.elem[j];
    L.length--;
    return OK;
}

int main() {
	int n; cin >> n;
    SqList L; 
    InitList(L);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ListInsert(L, i + 1, x);
    }
    int l, r; cin >> l >> r;
    for (int i = l; i <= r; i++) {
        ElemType e = i;
        int x = LocateElem(L, e);
        if (x)
            ListDelete(L, x, e);
    }
    for (int i = 1; i <= GetLength(L); i++) {
        ElemType e;
        GetElem(L, i, e);
        cout << e << " ";
    }
    return 0;
} 

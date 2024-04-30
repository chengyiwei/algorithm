#include <bits/stdc++.h>
#define MAXSIZE 10000
#define OK 1
#define ERROR 0
using namespace std;
typedef int ElemType;
typedef int Status;

//线性表
typedef struct List {
    int length;
    ElemType data[MAXSIZE];

    Status init_list() {
        length = 0;
        return OK;
    }
    
    Status vector_to_list(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            data[i] = A[i];
        }
        length = A.size();
        return OK;
    }

    Status insert (int i, ElemType e) { // 在第i个位置插入元素e
        if (i < 0 || i > length) return ERROR;
        if (length == MAXSIZE) return ERROR;
        for (int j = length; j > i; j--) {
            data[j] = data[j - 1];
        }
        data[i] = e;
        length++;
        return OK;
    }

    ElemType get_elem (int i) { // 获取第i个元素
        if (i < 0 || i >= length) return ERROR;
        return data[i];
    }

    Status delete_elem (int i) { // 删除第i个元素
        if (i < 0 || i >= length) return ERROR;
        for (int j = i; j < length - 1; j++) {
            data[j] = data[j + 1];
        }
        length--;
        return OK;
    }

    void print_list() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
} List;

List merge_list (List &L_A, List &L_B) {
    List L;
    L.init_list();
    int i = 0, j = 0;
    while (i < L_A.length && j < L_B.length) {
        if (L_A.data[i] < L_B.data[j]) {
            L.insert(L.length, L_A.data[i]);
            i++;
        } else {
            L.insert(L.length, L_B.data[j]);
            j++;
        }
    }
    while (i < L_A.length) {
        L.insert(L.length, L_A.data[i]);
        i++;
    }
    while (j < L_B.length) {
        L.insert(L.length, L_B.data[j]);
        j++;
    }
    return L;
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int m; cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    List L_A, L_B;
    L_A.init_list(); L_A.vector_to_list(A);
    L_B.init_list(); L_B.vector_to_list(B);
    auto L = merge_list(L_A, L_B);
    L_A.print_list();
    L_B.print_list();
    L.print_list();
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p;
    while (1) {
        p = (int*)malloc(4);
        // free(p); // 释放已分配的内存
    }
}
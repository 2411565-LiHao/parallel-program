#include<iostream>
#include<windows.h>
using namespace std;

const int N = 10000;
int b[N][N];
int a[N];
int sum[N];

void optimized_algorithm() {
    // 先初始化sum数组
    for(int i = 0; i < N; i++) {
        sum[i] = 0;
    }
    // 按行访问
    for(int j = 0; j < N; j++) {
        for(int i = 0; i < N; i++) {
            sum[i] += b[j][i] * a[j];
        }
    }
}

int main() {
    // 初始化数据
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            b[i][j] = i + j;
        }
        a[i] = i;
    }

    // 只执行一次算法
    optimized_algorithm();

    return 0;
}
#include<iostream>
#include<windows.h>
using namespace std;

const int N = 10000;
int b[N][N];
int a[N];
int sum[N];

void normal_algorithm() {
    for(int i = 0; i < N; i++){
        sum[i] = 0;
        for(int j = 0; j < N; j++){
            sum[i] += b[j][i] * a[j];
        }
    }
}

int main(){
    // 初始化
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            b[i][j] = i + j;
        }
        a[i] = i;
    }

    normal_algorithm();
    
    return 0;
}
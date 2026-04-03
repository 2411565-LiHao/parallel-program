#include<iostream>
using namespace std;
const int N = 1024;

int main(){
    int i;
    int a[N];
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    for(i = 0; i < N; i++){
        a[i]=i;
    }
    
    for(i = 0; i < N; i+=2){
        sum1 += a[i];
        sum2 += a[i+1];
    }
    sum = sum1 + sum2;
}
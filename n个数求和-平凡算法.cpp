#include<iostream> 
#include<windows.h> 
using namespace std; 

const int N = 1048576; 

int a[N]; 
int sum = 0; 

int main(){ 
    for(int i = 0; i < N; i++) a[i] = i; 
    
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);
    
    QueryPerformanceCounter(&start);
    // 循环100次，让VTune有足够时间采样
    for(int k = 0; k < 100; k++) {
        sum = 0;
        int i = 0; 
        for(; i < N - 3; i += 4){ 
            sum += a[i]; 
            sum += a[i+1]; 
            sum += a[i+2]; 
            sum += a[i+3]; 
        } 
        for(; i < N; i++){ 
            sum += a[i]; 
        } 
    }
    QueryPerformanceCounter(&end);
    
    double ms = (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
    cout << "N = " << N << endl;
    cout << "Time = " << ms << " ms (100 iterations)" << endl;
    cout << "Sum = " << sum << endl;
    
    return 0;
} 

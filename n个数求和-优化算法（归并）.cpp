#include<iostream> 
#include<windows.h> 
using namespace std; 

const int N = 1048576; 

int a[N]; 

int main(){ 
    for(int i = 0; i < N; i++) a[i] = i; 
    
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);
    
    QueryPerformanceCounter(&start);
    // 循环100次，让VTune有足够时间采样
    for(int k = 0; k < 100; k++) {
        for(int i = 0; i < N; i++) a[i] = i;
        
        for(int m = N; m > 1; m /= 2) { 
            int half = m / 2; 
            int i = 0; 
            for(; i < half - 3; i += 4) { 
                a[i]   = a[i*2]   + a[i*2+1]; 
                a[i+1] = a[(i+1)*2] + a[(i+1)*2+1]; 
                a[i+2] = a[(i+2)*2] + a[(i+2)*2+1]; 
                a[i+3] = a[(i+3)*2] + a[(i+3)*2+1]; 
            } 
            for(; i < half; i++) { 
                a[i] = a[i*2] + a[i*2+1]; 
            } 
        } 
    }
    QueryPerformanceCounter(&end);
    
    double ms = (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
    cout << "N = " << N << endl;
    cout << "Time = " << ms << " ms (100 iterations)" << endl;
    cout << "Sum = " << a[0] << endl;
    
    return 0;
} 

#include<iostream> 
#include<windows.h> 
using namespace std; 

const int MAX_N = 1048576; 

int a[MAX_N]; 

// 平凡算法 - 4路展开 
void normal_unroll(int n) {
    int sum = 0;
    int i = 0;
    for(; i < n - 3; i += 4) {
        sum += a[i];
        sum += a[i+1];
        sum += a[i+2];
        sum += a[i+3];
    }
    for(; i < n; i++) {
        sum += a[i];
    }
}

int main() {
    int test_N[] = {1024, 2048, 4096, 8192, 16384, 32768, 65536, 
                    131072, 262144, 524288, 1048576};
    
    cout << "========== Normal Algorithm (4-way unroll) ==========" << endl;
    cout << "N\t\tTime(ms)" << endl;
    
    for(int k = 0; k < 11; k++) {
        int N = test_N[k];
        
        LARGE_INTEGER start, end, freq;
        QueryPerformanceFrequency(&freq);
        
        for(int i = 0; i < N; i++) a[i] = i;
        QueryPerformanceCounter(&start);
        long counter = 0;
        while(true) {
            QueryPerformanceCounter(&end);
            double elapsed = (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
            if(elapsed >= 10) break;
            counter++;
            normal_unroll(N);
        }
        QueryPerformanceCounter(&end);
        double avg_ms = (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart / counter;
        
        cout << N << "\t\t" << avg_ms << endl;
    }
    
    return 0;
}

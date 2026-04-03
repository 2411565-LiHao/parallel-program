#include<iostream> 
#include<windows.h> 
using namespace std; 

const int MAX_N = 1048576; 

int a[MAX_N]; 

// 归并算法 - 4路展开 
void merge_unroll(int n) {
    for(int m = n; m > 1; m /= 2) {
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

int main() {
    int test_N[] = {1024, 2048, 4096, 8192, 16384, 32768, 65536, 
                    131072, 262144, 524288, 1048576};
    
    cout << "========== Merge Algorithm (4-way unroll) ==========" << endl;
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
            merge_unroll(N);
        }
        QueryPerformanceCounter(&end);
        double avg_ms = (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart / counter;
        
        cout << N << "\t\t" << avg_ms << endl;
    }
    
    return 0;
}

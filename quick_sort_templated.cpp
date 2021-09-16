//
// Created by jay on 9/8/21.
//

#include <iostream>
#include <assert.h>

template<typename T>
void show(T *x, long N) {
    for (long i = 0; i < N; ++i)
        std::cout << x[i] << " " << std::endl;
}

template<typename T>
int isSorted(T *a, long lo, long hi) {
    for (long i = lo + 1; i < hi; i++)
        if (a[i] < a[i-1]) return 0;
    return 1;
}
template<typename T>
void selection_sort(T *source, long n) {
    for (long i = 0; i < n; ++i) {
        long min_ind = i;
        T min_val = source[i];
        for (long j = i + 1; j < n; ++j)
            if (source[j] < min_val) {
                min_ind = j;
                min_val = source[j];
            }
        std::swap(source[i], source[min_ind]);
    }
}

template<typename T>
int partition(T *source, long lo, long hi ) {
    long i = lo;
    long j = hi + 1;
    T peak_i = *(source+lo);
    T peak_j = *(source+hi);
    T v = source[lo];
    while(true) {
        while(source[++i] < v) {
            peak_i = *(source+i);
            // added a minus one
            //i >= ? ??
            if (i == hi) break;
        }
        while( v < source[--j]) {
            peak_j = *(source+j);
            if (j == lo) break;
        }
        if (i >= j) break;
        std::swap(source[i], source[j]);
      }
    std::swap(source[lo], source[j]);
    return j;
}

template<typename T>
void quick_sort(T *source, const long lo, long hi) {
// zero length array
    if (hi < lo) return;
    unsigned long j = partition(source, lo, hi);
    quick_sort(source, lo, j - 1);
    quick_sort(source, j + 1, hi);
}
double average_run_times(double * times, long n) {
    double sum=0.0;
    for (long i = 0; i<n; ++i) {
        sum+=times[i];
    }
    return sum/n;
}
template<typename T>
int main(int argc, char **argv) {
    if (argc == 3) {
        const unsigned long N = atoi(argv[1]);
        T x*= argv[2],
        quick_sort(x,0,N-1);
//        assert(isSorted(x,0,N));
        show(x,10);
    } else
        std::cerr << "Usage: sort<T> <n> <*T>" << std::endl;
//    MixedDyad<int, string> product(1, "Hammer");
    return 0;
}


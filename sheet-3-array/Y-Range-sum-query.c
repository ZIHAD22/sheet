#include <stdio.h>

#define MAX_N 100000

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    long long A[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    
    long long prefix[MAX_N + 1];
    prefix[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }
    
    for (int i = 0; i < Q; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        printf("%lld\n", prefix[R] - prefix[L - 1]);
    }

    return 0;
}

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[N];
    int frequency[M];  

    for (int i = 0; i < M; i++) {
        frequency[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        frequency[A[i] - 1]++;
    }

    for (int i = 0; i < M; i++) {
        printf("%d\n", frequency[i]);
    }

    return 0;
}

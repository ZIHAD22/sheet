#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int min = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }

    int freq = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == min) {
            freq++;
        }
    }

    if (freq % 2 == 1) {
        printf("Lucky\n");
    } else {
        printf("Unlucky\n");
    }

    return 0;
}

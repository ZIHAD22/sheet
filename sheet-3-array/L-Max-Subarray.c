#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int A[100];

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        for (int i = 0; i < N; i++) {
            int maxVal = A[i];
            for (int j = i; j < N; j++) {
                if (A[j] > maxVal) {
                    maxVal = A[j];
                }
                printf("%d ", maxVal);
            }
        }
        printf("\n");
    }

    return 0;
}

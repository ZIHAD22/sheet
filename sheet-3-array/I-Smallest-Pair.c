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

        int min = 2000000000;

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int result = A[i] + A[j] + j - i;
                if (result < min) {
                    min = result;
                }
            }
        }

        printf("%d\n", min);
    }

    return 0;
}

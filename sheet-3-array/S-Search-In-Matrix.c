#include <stdio.h>

int main() {
    int N, M, X;
    scanf("%d %d", &N, &M);

    int matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    scanf("%d", &X);

    int found = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == X) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (found)
        printf("will not take number\n");
    else
        printf("will take number\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h> 

int main() {
    int N;
    scanf("%d", &N);

    int matrix[N][N];
    int primary_diagonal_sum = 0, secondary_diagonal_sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);

            if (i == j) {
                primary_diagonal_sum += matrix[i][j];
            }

            if (i + j == N - 1) {
                secondary_diagonal_sum += matrix[i][j];
            }
        }
    }

    int result = abs(primary_diagonal_sum - secondary_diagonal_sum);

    printf("%d\n", result);

    return 0;
}

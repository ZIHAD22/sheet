#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char digits[N]; 
    scanf("%s", digits);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += digits[i] - '0';
    }

    printf("%d\n", sum);

    return 0;
}

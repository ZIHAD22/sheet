#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0\n");
        return 0;
    }
    if (n == 2) {
        printf("1\n");
        return 0;
    }

    long long fib1 = 0, fib2 = 1, fibN;
    for (int i = 3; i <= n; i++) {
        fibN = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibN;
    }

    printf("%lld\n", fibN);

    return 0;
}

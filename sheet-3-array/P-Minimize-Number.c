#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;
    while (1) {
        int all_even = 1;
        for(int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                all_even = 0;
                break;
            }
        }

        if (!all_even) break;

        for(int i = 0; i < n; i++) {
            a[i] /= 2;
        }

        count++;
    }

    printf("%d\n", count);
    return 0;
}

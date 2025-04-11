#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    for (int i = 0; i < Q; i++) {
        int X;
        scanf("%d", &X);
        int left = 0, right = N - 1;
        int found = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == X) {
                found = 1;
                break;
            } else if (A[mid] < X) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (found) {
            printf("found\n");
        } else {
            printf("not found\n");
        }
    }
    return 0;
}

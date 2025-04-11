#include <stdio.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    sort(a, n);
    sort(b, n);

    int isPermutation = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            isPermutation = 0;
            break;
        }
    }

    if(isPermutation)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}

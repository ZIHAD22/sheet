#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    char S[25]; 
    scanf("%s", S);

    int valid = 1;

    if (S[A] != '-') {
        valid = 0;
    }

    for (int i = 0; i < A + B + 1; i++) {
        if (i == A) continue;
        if (!isdigit(S[i])) {
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char S[100001];
        scanf("%s", S);
        if (strstr(S, "010") || strstr(S, "101"))
            printf("Good\n");
        else
            printf("Bad\n");
    }
    return 0;
}

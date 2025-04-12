#include <stdio.h>
#include <ctype.h>

int main() {
    char S[100001];
    scanf("%s", S);
    for (int i = 0; S[i]; i++) {
        if (S[i] == ',')
            putchar(' ');
        else if (isupper(S[i]))
            putchar(tolower(S[i]));
        else if (islower(S[i]))
            putchar(toupper(S[i]));
        else
            putchar(S[i]);
    }
    return 0;
}

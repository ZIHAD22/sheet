#include <stdio.h>

int main() {
    char c;
    while ((c = getchar()) != '\\' && c != EOF) {
        putchar(c);
    }
    return 0;
}

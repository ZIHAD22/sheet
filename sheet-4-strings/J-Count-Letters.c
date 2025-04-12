#include <stdio.h>
#include <string.h>

int main() {
    char S[10000001];
    int count[26] = {0};
    scanf("%s", S);
    
    for (int i = 0; S[i]; i++) {
        count[S[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c : %d\n", i + 'a', count[i]);
        }
    }
    
    return 0;
}

#include <stdio.h>

int main() {
    long long n , fac , result;
    scanf("%lld" , &n);

    result = 1;

    for(int i = 1; i <= n; i++){
        scanf("%lld" , &fac);
        for(int j = 1; j <= fac ; j++){
            result = result * j;
        }

        printf("%lld\n" , result);
        result = 1;

    }

    return 0;
}
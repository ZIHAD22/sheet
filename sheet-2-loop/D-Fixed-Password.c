#include <stdio.h>

int main() {
    int n;
    while(scanf("%d" , &n) == 1){
        if(n == 1999){
            printf("Correct\n");
            break;
        }else{
            printf("Wrong\n");
        }
    }

    return 0;
}
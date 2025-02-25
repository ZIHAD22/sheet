#include <stdio.h>

int main() {
    int n , result;
    result = 0;

    scanf("%d" , &n);

    if(n == 1){
        printf("NO");
        return 0;
    }


    for(int i = 2 ; i <= n ; i++){
        if(n%i == 0){
            result++;
        }
    }

    if(result > 1){
        printf("NO");
    }else{
        printf("YES");
    }
    

    return 0;
}
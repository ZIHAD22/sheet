#include <stdio.h>
#include <limits.h>

int main() {

    int n , num , max;
    scanf("%d" , &n);

     max = INT_MIN;

    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &num);
        if(max < num)
            max  = num;
    }

    printf("%d" , max);

    return 0;
}
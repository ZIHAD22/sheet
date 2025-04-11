#include<stdio.h>

int main () {

    int n;
    scanf("%d" , &n);

    int nums[n];

    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &nums[i]);
    }


    int isPali = 1;
    for(int i = 0 ; i < n/2 ; i++){
        if(nums[i] != nums[n - 1 - i]){
            isPali = 0;
            break;
        }
    }

    if(isPali){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}
#include <stdio.h>
#include<limits.h>

int main() {

    int n , find = INT_MAX , position = 0;
    scanf("%d" , &n);


    int arr[n];

    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &arr[i]);
    }


    for(int i = 0 ; i < n ; i++){
        if(find > arr[i] ){
            find = arr[i];
            position = i+1;
        }
    }

    printf("%d %d" , find , position);


    

    return 0;
}
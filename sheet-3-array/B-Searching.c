#include <stdio.h>

int main() {

    int n , find , isFind = -1;
    scanf("%d" , &n);

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &arr[i]);
    }

    scanf("%d" , &find);

    for(int i = 0 ; i < n ; i++){
        if(arr[i] == find){
            isFind = i;
            break;
        }
    }

    printf("%d" , isFind);
    

    return 0;
}
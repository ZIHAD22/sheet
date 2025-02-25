#include <stdio.h>

int main() {
    int a , b;
    int found = 0;

    scanf("%d %d" , &a ,&b);


    for(int i = a ; i <= b ; i++){
        if(i%10 == 4 && i%10 == 7){
            printf("%d" , i);
        }
    }


    return 0;
}

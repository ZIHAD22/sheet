#include <stdio.h>

int main() {
    int n , num = 0 , temp;
    scanf("%d" , &n);

    temp = n;

    
    while(n > 0){
        num = num * 10 + n % 10;
        
        n = n/10;
        
    }

    if(num == temp){
        printf("%d\nYES\n" , num);
    }else{
        printf("%d\nNO\n" , num);

    }

    return 0;
}
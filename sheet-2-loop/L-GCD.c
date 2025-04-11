#include <stdio.h>

int main() {
    int a, b;
    
    
    scanf("%d %d", &a, &b);

    while (b != 0) {
        int temp = b; // 12 // 4
        b = a % b; // 8 % 12 = 4 // 12 % 4 = 0 
        a = temp;  // 12 // 4  
    }
    
    printf("%d" , a);
    
    
    return 0;
}

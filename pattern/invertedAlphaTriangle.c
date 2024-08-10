#include<stdio.h>

int main(){

    char n;
    printf("Enter the number for triangle : ");
    scanf("%c",&n);

    for(int i=n; i>='A'; i--){
        for(int j='A'; j<=i; j++){
            printf("%c",j);
        }
    printf("\n");
    }

    return 0;
}
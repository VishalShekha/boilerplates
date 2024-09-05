#include<stdio.h>

int main(){

    char h;
    printf("Enter the alphabet :");
    scanf("%c",&h);

    for(int i='A'; i<=h; i++){
        for(int j='A'; j<=i; j++){
            printf("%c",j);
        }
        printf("\n");
    }

    return 0;
}
#include<stdio.h>

int main(){

    char h;
    printf("Enter the alphabet of the triangle :");
    scanf("%c",&h);

    for(int i='A'; i<=h; i++){
        for(int j='A'; j<=i; j++){
            printf("%c",i);
        }
        printf("\n");
    }

    return 0;
}
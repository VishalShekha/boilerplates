#include<stdio.h>

int main(){

    int h;
    printf("Enter the height of the triangle :");
    scanf("%d",&h);

    for(int i=1; i<=h; i++){
        for(int j=1; j<=i; j++){
            printf("%d",j);
        }
        printf("\n");
    }

    return 0;
}
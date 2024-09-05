#include<stdio.h>

int main(){

    int l,b;
    printf("Enter the length and the breath : ");
    scanf("%d %d",&l,&b);
    for(int i=0; i<l; i++){
        for(int j=0; j<b; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
#include<stdio.h>

int printP(int n){
    for(int i =n-1; i>=0;i--){
        //space
        for(int j=0; j<n-i+1;j++){
            printf(" ");
        }
        // star
        for(int j=0; j<(2*i)+1;j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printP(n);
    return 0;
}
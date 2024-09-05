#include<stdio.h>

int printU(int n){
    for(int i =0; i<n;i++){
        //space
        for(int j=0; j<n-i+1;j++){
            printf(" ");
        }
        //star
        for(int j=0; j<(2*i)+1;j++){
            printf("*");
        }
        printf("\n");
    }
}
int printL(int n){
    for(int i =n-1; i>=0;i--){
        //space
        for(int j=0; j<n-i+1;j++){
            printf(" ");
        }
        //star
        for(int j=0; j<(2*i)+1;j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printU(n);
    printL(n);
    return 0;
}
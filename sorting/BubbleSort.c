#include<stdio.h>

void BubbleSort(int *a, int n){
    
}

int main(){

    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);    
    int a[n];
    printf("Enter the elements : ");
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    BubbleSort(a,n);

    for(int i=0; i<n; i++) printf("%d",a[i]);

    return 0;
}
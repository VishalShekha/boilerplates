#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *a, int n){
    for(int i=n-1;i>=1;i--){
        int DidSwap = 0;
        for(int j=0;j<=i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                DidSwap = 1;
            } 
        }
        if (DidSwap == 0) break;
    }
}

int main(){

    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);    
    int a[n];
    printf("Enter the elements : ");
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    BubbleSort(a,n);

    for(int i=0; i<n; i++) printf("%d ",a[i]);

    return 0;
}
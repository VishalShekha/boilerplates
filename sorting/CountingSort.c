#include<stdio.h>
#include<stdlib.h>

void countingSort(int *a, int n, int max){
    int *temp = (int*)calloc(sizeof(int),max+1);

    for(int i=0;i<n;i++){
        temp[a[i]]++;
    }
    int j = 0;
    for(int i=0;i<max+1;i++){
        while(temp[i]>0){
            a[j++] = i;
            temp[i]--;
        }
    }
}

int main(){

    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);    
    int a[n];
    int max=0;
    printf("Enter the elements : ");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if (a[i]>max) max = a[i];
    } 

    countingSort(a,n,max);

    for(int i=0; i<n; i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}
#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int low, int high){
    int p = a[high];
    int i = low-1;

    for(int j=low;j<=high-1;j++){
        if(a[j] <= p){
            i++;
            swap(a+i,a+j);
        }
    }

    swap(a+high,a+i+1);
    return i+1;
}

void quicksort(int *a, int low, int high){
    if(low<high){
        int pi = partition(a,low,high);

        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);

    }
}

int main(){

    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);    
    int a[n];
    printf("Enter the elements : ");
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    quicksort(a,0,n-1);

    for(int i=0; i<n; i++) printf("%d ",a[i]);

    return 0;
}
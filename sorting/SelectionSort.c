#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int *a, int n){
    int min_ind;
    for(int i = 0;i<n-1;i++){
        min_ind = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_ind]) min_ind = j;
        }
        if(min_ind!=i) swap(&a[i],&a[min_ind]);
    }

}

int main(){

    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);    
    int a[n];
    printf("Enter the elements : ");
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    SelectionSort(a,n);

    for(int i=0; i<n; i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}
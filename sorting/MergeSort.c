#include<stdio.h>

void merge(int *a, int low, int mid, int high){
    int temp[high-low+1];
    int k=0;
    int left = low;
    int right = mid +1;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp[k] = a[left];
            left++;
        }
        else{
            temp[k] = a[right];
            right++;
        }
        k++;
    }
    while(left<=mid){
        temp[k] = a[left];
        left++;
        k++;
    }
    while(right<=high){
        temp[k] = a[right];
        right++;
        k++;
    }
    for(int i = 0;i<k;i++) a[low+ i] = temp[i];
}

void MergeSort(int *a, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main(){

    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);    
    int a[n];
    printf("Enter the elements : ");
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    MergeSort(a,0,n-1);

    for(int i=0; i<n; i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}
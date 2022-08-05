#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int low, int mid, int high);
void merge_sort(int A[], int low, int mid);

int main(){
    int n; 
    printf("Enter size of array: ");
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        printf("Enter element - %d: ", i);
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    merge_sort(A, 0, n);
    printf("\n");
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    return 0;
}


void merge_sort(int A[], int low, int high){
    if(high - low == 1) return;
    int mid = (low + high)/2;
    merge_sort(A, low, mid);
    merge_sort(A, mid, high);
    merge(A, low, mid, high);
    
    return;
}

void merge(int A[], int low, int mid, int high){
    int i, j, k;
    i = low; 
    j = mid;
    k = 0;
    int B[high - low];
    while(i < mid && j < high){
        if(A[i] < A[j]) B[k++] = A[i++];
        else B[k++] = A[j++];
    }

    while(i < mid){
        B[k++] = A[i++];
    }
    while(j < high){
        B[k++] = A[j++];
    }
    k = 0;
    for(int i = low; i < high; i++) A[i] = B[k++];
    return;
}
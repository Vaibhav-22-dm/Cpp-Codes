#include <stdio.h>
#include <stdlib.h>

void selectionsort(int A[], int n);

int main(){
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int A[n];

    for(int i = 0; i < n; i++){
        printf("Enter element - %d: ", i);
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
    
    selectionsort(A,  n); // Called the selectionsort function

    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    
    return 0;
}

void selectionsort(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            //Whenever we find a element lesser than the ith element then we swap that element with the ith element.
            //This procedure goes on till first n - 1 elements are compared and positioned accordingly.
            //Basically we keep finding the smallest element in the subarray (i,n-1) and then place it at the ith index.
            if(A[i] > A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    return;
}
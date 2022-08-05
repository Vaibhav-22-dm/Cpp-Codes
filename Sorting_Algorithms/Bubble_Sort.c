#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int A[], int n);

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
    printf("\n");

    bubble_sort(A, n);
    
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    return 0;
}

//For an array of size n, we iterate over the array n - 1 times. 
//In each iteration i, we move the largest element of the sub array(formed by 0 to n-1-i elements) to the rightmost position.
//Doing this leads to sorting the array in (n-1)(n)/2 steps which means Time complexity is of O(n^2).
 
void bubble_sort(int A[], int n){
    for(int k = 0; k < n - 1; k++){
        int isSorted = 1;
        int i;
        for(i = 0; i < n - 1 - k; i++){
            if(A[i+1]<A[i]){
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                isSorted = 0;
                for(int l = 0; l < n; l++) printf("%d ", A[l]);
                printf("\n");
            }
        }
        if(isSorted) return;
        printf("%d\n", A[i]);
        for(int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n");
    }
    return;
}

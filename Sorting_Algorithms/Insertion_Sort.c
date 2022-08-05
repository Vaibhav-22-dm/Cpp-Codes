#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int A[], int n);

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

    insertion_sort(A, n);
    
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    return 0;
}

   // Example:  12, 54, 65, 07, 23, 09
   //  -1   0    1   2   3   4   5 --> i & j
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 

void insertion_sort(int A[], int n){
    for(int i = 1; i < n; i++){
        int key = A[i];
        int j = i -1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    return;
}
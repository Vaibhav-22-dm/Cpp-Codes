#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int low, int high);
void quicksort(int A[], int low, int high);

int main(){
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int A[n];

    for(int i = 0; i < n; i++){
        printf("Enter element - %d: ", i);
        scanf("%d", &A[i]);
    }

    quicksort(A, 0, n); // Called the quicksort function

    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    
    return 0;
}

void quicksort(int A[], int low, int high){
    if(low>=high) return;
    //Recursion stops when the elements of comparison reduced to only a single value.

    quicksort(A, low, partition(A, low, high)); 
    //Sort left subarray
    //Also partition(A, low, high) will position the element at index = low at its correct position and then return the index of its correct position

    quicksort(A, partition(A, low, high) + 1, high);
    //Sort right subarray
    //Also partition(A, low, high) will position the element at index = partition(A, low, high) + 1 at its correct position and then return the index of its correct position.

    return;
}

// 5 2 6 1 7

int partition(int A[], int low, int high){
    int i = low + 1, j = high - 1;
    //i starts from the first element.
    //j starts from the last element.

    int pivot = A[low];
    //pivot stores the value which is being compared to be positioned.

    do{
        while (A[i] <= pivot)
        {
            i++;
        }
        //Finding the rightmost element lesser than the pivot element.

        while (A[j] > pivot)
        {
            j--;
        }
        //Finding the leftmost element from the end which is greater than the pivot element.

        if(i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        //Exchnaging the elements found in the above two while loops.

    } while(i < j); 
    //Above loop runs till the index of i exceeds that of j.
     
    //After this step we just swap the pivot with jth element.
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
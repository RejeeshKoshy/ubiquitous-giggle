/*----------------------------
MegeSort.c

Rejeesh Koshy
XX-10-2024
----------------------------*/
#include <stdio.h>

void input(int N, int A[20]);
void output(int N, int A[20]);
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int main() {
    int N, A[20];
    printf("MERGE SORT\n");
    printf("-----------\n");

    printf("Enter the number of elements:\n");
    scanf("%d", &N);

    printf("Enter the elements:\n");
    input(N, A);

    printf("\nDisplay elements before sorting:\n");
    output(N, A);

    // Corrected function call
    mergeSort(A, 0, N - 1);
    printf("\nDisplay elements after sorting:\n");
    output(N, A);

    return 0;
}

//-----------------------------------
void input(int N, int A[20]) {
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
}

//-----------------------------------
void output(int N, int A[20]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}
//-----------------------------------
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int lowArr[n1], highArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        lowArr[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        highArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (lowArr[i] <= highArr[j]) {
            arr[k] = lowArr[i];
            i++;
        } else {
            arr[k] = highArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of lowArr[], if any
    while (i < n1) {
        arr[k] = lowArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of highArr[], if any
    while (j < n2) {
        arr[k] = highArr[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [low-high]
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        // Calculate the midpoint
        int mid = low + (high - low) / 2;

        // Sort first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}
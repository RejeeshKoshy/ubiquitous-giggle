/*----------------------------
LinearNBinarySearch.c

Rejeesh Koshy
XX-10-2024
----------------------------*/

#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int low, int high, int key);
void sortArray(int arr[], int n);

int main() {
    int n, key, choice, result;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    // Menu for searching methods
    printf("Choose search method:\n1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Perform Linear Search
            result = linearSearch(arr, n, key);
            if (result != -1) {
                printf("Element %d found at index %d using Linear Search.\n", key, result);
            } else {
                printf("Element %d not found using Linear Search.\n", key);
            }
            break;
        
        case 2:
            // Sort the array before performing Binary Search
            sortArray(arr, n);
            printf("Sorted array for Binary Search: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

            // Perform Binary Search
            result = binarySearch(arr, 0, n - 1, key);
            if (result != -1) {
                printf("Element %d found at index %d using Binary Search.\n", key, result);
            } else {
                printf("Element %d not found using Binary Search.\n", key);
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// Function to perform Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return the index where the element is found
        }
    }
    return -1;  // Element not found
}

// Function to perform Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the key is at the middle
        if (arr[mid] == key) {
            return mid;
        }

        // If the key is smaller, ignore the right half
        if (arr[mid] > key) {
            high = mid - 1;
        }
        // If the key is larger, ignore the left half
        else {
            low = mid + 1;
        }
    }
    return -1;  // Element not found
}

// Function to sort the array for Binary Search
void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
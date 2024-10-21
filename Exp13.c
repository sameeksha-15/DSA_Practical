#include <stdio.h>
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
            minIdx = j;
            temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
    }
}
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[100], n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    do {
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            selectionSort(arr, n);
            printf("Array after Selection Sort: ");
            displayArray(arr, n);
            break;
            case 2:
            bubbleSort(arr, n);
            printf("Array after Bubble Sort: ");
            displayArray(arr, n);
            break;
            case 3:
            insertionSort(arr, n);
            printf("Array after Insertion Sort: ");
            displayArray(arr, n);
            break;
            case 4:
            printf("Exiting program.\n");
            break;
            default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

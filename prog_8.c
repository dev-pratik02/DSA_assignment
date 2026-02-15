#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

long long comparisons = 0;
long long swaps = 0;

void resetCounters() 
{
    comparisons = 0;
    swaps = 0;
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            comparisons++;
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i;
        for (int j = i + 1; j < n; j++) 
        {
            comparisons++;
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) 
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swaps++;
        }
    }
}

void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) 
        {
            comparisons++;
            if (arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else 
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        swaps++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        swaps++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        swaps++;
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() 
{
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = (rand() % 1000) + 1;

    printf("\nOriginal array:\n");
    printArray(arr, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    resetCounters();

    switch (choice) 
    {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nSorted array:\n");
    printArray(arr, n);

    printf("\nTotal Comparisons: %lld\n", comparisons);
    printf("Total Swaps/Moves: %lld\n", swaps);

    return 0;
}

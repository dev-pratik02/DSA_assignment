#include <stdio.h>
#define MAX_SIZE 100

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) 
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;
    if(right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if(smallest != i) 
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) 
{
    for(int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) 
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n, const char *label) 
{
    printf("%s: ", label);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }   
    printf("\n");
}

int main() 
{
    int data[] = {12, 11, 13, 5, 6, 7}; // unsorted array
    int n = sizeof(data)/sizeof(data[0]);

    int minHeap[MAX_SIZE], maxHeap[MAX_SIZE];
    for(int i = 0; i < n; i++) 
    {
        minHeap[i] = data[i];
        maxHeap[i] = data[i];
    }

    // Build Min Heap
    buildMinHeap(minHeap, n);
    printArray(minHeap, n, "Min Heap");

    // Build Max Heap
    buildMaxHeap(maxHeap, n);
    printArray(maxHeap, n, "Max Heap");

    return 0;
}

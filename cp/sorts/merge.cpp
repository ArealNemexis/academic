#include <iostream>

using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    //preencher subarrays
    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    /* Merge os arrays temporarios de volta para o arr[start..end]*/
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array recebido\n");
    printArray(arr, arr_size);

    mergesort(arr, 0, arr_size - 1);

    printf("\nArray ordenado \n");
    printArray(arr, arr_size);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long comparisons = 0;   
long long movements = 0;     
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int size = high - low + 1;
    int *temp = (int *)malloc(size * sizeof(int));
    while (i <= mid && j <= high)
    {
        comparisons++;   
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];  
            movements++;   
        }
        else
        {
            temp[k++] = a[j++];
            movements++;
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
        movements++;
    }
    while (j <= high)
    {
        temp[k++] = a[j++];
        movements++;
    }
    
    for (i = low, k = 0; i <= high; i++, k++)
    {
        a[i] = temp[k];
        movements++;
    }
    free(temp);
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    srand(time(NULL));
    printf("\nUnsorted array:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    clock_t start = clock();
    mergeSort(a, 0, n - 1);
    clock_t end = clock();
    printf("\n\nSorted array:\n");
    for (i = 0; i < n; i++)
    printf("%d ", a[i]);
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nExecution Time: %f seconds\n", time_taken);
    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Number of Movements : %lld\n", movements);
       return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;
long long movements = 0;

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n)
    {
        comparisons++;
        if (a[left] > a[largest])
            largest = left;
    }

    if (right < n)
    {
        comparisons++;
        if (a[right] > a[largest])
            largest = right;
    }

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        movements += 3;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n-1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        movements += 3;

        heapify(a, i, 0);
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

    heapSort(a, n);

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
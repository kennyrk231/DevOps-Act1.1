#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comp = 0, move = 0;

void merge(int a[], int l, int m, int h)
{
    int i=l, j=m+1, k=0, t[h-l+1];

    while(i<=m && j<=h)
    {
        comp++;
        if(a[i] < a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
        move++;
    }

    while(i<=m){ t[k++] = a[i++]; move++; }
    while(j<=h){ t[k++] = a[j++]; move++; }

    for(i=l, k=0; i<=h; i++,k++)
    {
        a[i] = t[k];
        move++;
    }
}

void mergeSort(int a[], int l, int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,l,m,h);
    }
}

int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);

    int a[n];
    srand(time(0));

    printf("Unsorted:\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }

    clock_t s=clock();
    mergeSort(a,0,n-1);
    clock_t e=clock();

    printf("\nSorted:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime: %f",(double)(e-s)/CLOCKS_PER_SEC);
    printf("\nComparisons: %lld",comp);
    printf("\nMovements: %lld",move);

    return 0;
}
print("changes done")

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void selectionSort(int arr[], int n);

void selectionSort(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        int min = arr[i];
        int min_index = 0;

        for(int j = i; j < n; j++)
        {
            if(min > arr[j]){
                min = arr[j];
                min_index = j;

                int temp = arr[i];
                arr[i] = min;
                arr[min_index] = temp;
            }
        }

        printf("\n");
        printf("Pass%d: \n", i + 1);
        for(int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("\nSorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nMemory occupied by input array: %d bytes\n", n*sizeof(int));
    printf("Memory occupied by variable i: %d bytes\n", 1*sizeof(int));
    printf("Memory occupied by variable j: %d bytes\n", 1*sizeof(int));
    printf("Memory occupied by variable temp: %d bytes\n", 1*sizeof(int));
    printf("Total Memory occupied: %d bytes\n", n*sizeof(int) + 1*sizeof(int) + 1*sizeof(int) + 1*sizeof(int));
}

int main(){
    clock_t start_t, end_t;
    double total_t;

    start_t = clock();

    int size = 0;
    printf("\nEnter the number of elements to sort: \n");
    scanf("%d", &size);

    int *arr = (int*)malloc(size * sizeof(int));

    printf("\nPlease enter the %d numbers: \n", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
        fflush(stdin);
    }

    selectionSort(arr, size);
    end_t = clock();

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTotal time taken by CPU: %f\n", end_t);
    printf("\nTotal time taken by CPU: %f\n", start_t);
    printf("\nTotal time taken by CPU: %f\n", total_t);

    return 0;
}

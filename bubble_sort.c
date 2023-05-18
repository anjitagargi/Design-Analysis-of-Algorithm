#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void bubbleSort(int arr[], int n){
for(int i = 0; i < n - 1; i++)
{
for(int j = 0; j < n - i - 1; j++)
{
if(arr[j] >= arr[j+1]){
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
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
printf("\nSorted array of the given array : \n");
for(int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
printf("\nMemory occupied by input array: %d bytes\n", n*sizeof(int));
printf("Memory occupied by variable i: %d bytes\n", 1*sizeof(int));
printf("Memory occupied by variable j: %d bytes\n", 1*sizeof(int));
printf("Memory occupied by variable temp: %d bytes\n", 1*sizeof(int));
}
int main(){
int size = 0;
clock_t start_t, end_t;
double total_t;
start_t = clock();

printf("Enter the number of elements to sort: \n");
scanf("%d", &size);
int *arr = (int*)malloc(size * sizeof(int));
printf("\n enter the %d numbers: \n", size);
for(int i = 0; i < size; i++){
scanf("%d", &arr[i]);
fflush(stdin);
}
bubbleSort(arr, size);
end_t = clock();
total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("\nTotal time taken by CPU: %f\n", total_t);

return 0;
}
#include <stdio.h>
#define DIM 10

int binarySearch(int [], int, int);

int main(){
    int arr[DIM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num;

    scanf("%d", &num);

    printf("%d", binarySearch(arr, DIM, num));

    return 0;
}

int binarySearch(int arr[], int dim, int num){

    if(arr[dim/2] == num)  
        return 1;
    if(arr[dim] != num && dim == 1)
        return 0;
    if(num > arr[dim/2]){
        printf("Maggiore");
        return binarySearch(arr + (dim/2), dim/2, num);
        }
    if(num < arr[dim/2])
        return  binarySearch(arr, dim/2, num);
}
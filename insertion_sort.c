# include <stdio.h>

void printarray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubblesort(int *arr, int n) {
    int temp;
    int isSorted = 0;
    for(int i = 0; i < n-1; i++) {
        printf("working on pass number %d\n", i+1);
        isSorted = 1;
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1] ) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted) {
            return;
        }
    }
}

void insertionsort(int *arr, int n) {
    int key, j;
    for(int i = 1; i<= n-1; i++ ) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {

    int arr[100];
    int n;

    printf("enter the length of array ");
    scanf("%d", &n);

    printf("enter the elements of array ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    

    printf("array before sorting \n");
    printarray(arr, n);

    insertionsort(arr, n );

    printf("array after sorting \n");
    printarray(arr, n);


    return 0;
}

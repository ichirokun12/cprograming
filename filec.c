# include <stdio.h>
# include <conio.h>

int main() {

    int n;
    int arr[100];
    int max, flor, i;

    printf("enter the number \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
    printf("%d \n", arr[i]);
    }
     
     max = arr[0];
     for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
     }

     for(flor = max; flor >= 1; flor--) {
        for(i = 0; i < n; i++) {
            if(arr[i] >=  flor) {
                printf("*");
            } else {
                printf(" ");

            }
        }
        printf("\n");
     }
    return 0;
}
#include <stdio.h>

int main() {
    int n1, n2;

    printf("Enter the number of values for the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter the values:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of values for the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter the values:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int diff[n2];
    int c = 0;

    int i = n1 - 1;
    int j = n2 - 1;
    int k = n2 - 1;

    while (k >= 0) {
        int d = 0;
        int a1v = i >= 0 ? arr1[i] : 0;
        if (arr2[j] + c >= a1v) {
            d = arr2[j] + c - a1v;
            c = 0;
        } else {
            d = arr2[j] + c + 10 - a1v;
            c = -1;
        }

        diff[k] = d;

        i--;
        j--;
        k--;
    }

    int idx = 0;
    while (idx < n2) {
        if (diff[idx] == 0) {
            idx++;
        } else {
            break;
        }
    }

    while (idx < n2) {
        printf("%d\n", diff[idx]);
        idx++;
    }

    return 0;
}

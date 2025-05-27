#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the matrix n: ");
    scanf_s("%d", &n);

    int** A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        A[i] = (int*)malloc(n * sizeof(int));


    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf_s("%d", &A[i][j]);


    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }

 
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i + j < n - 1)
                sum += A[i][j];

  
    printf("Transformed matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("Sum of elements above the secondary diagonal: %d\n", sum);

   
    for (int i = 0; i < n; i++)
        free(A[i]);
    free(A);

    return 0;
}

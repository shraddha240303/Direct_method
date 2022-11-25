#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a[100][100], b[100][1], x[100][1], sum, c, d;
    int i, j, k, n;
    printf ("Enter the number of rows: ");
    scanf ("%d", &n);

    // for entering the matrix
    for (i=0; i<n; i++){
        printf ("\nEnter the %d equation coefficients\n", i+1);
        for (j=0; j<n; j++){
            printf ("Enter coefficient of x%d : ", j+1);
            scanf ("%lf", &a[i][j]);
        }
        printf ("Enter variable b%d : ", i+1);
        scanf ("%lf", &b[i][0]);
    }

    if (a[0][0]==0){
        printf ("Please, enter the a[0][0] value other than zero");
        exit(0);
    }

    // for making upper triangular matrix
    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            c = -(a[j][i])/a[i][i];
            for (k=i; k<n; k++){
                d = a[i][k]*c;
                a[j][k] = a[j][k] + d;
            }
            d = b[i][0]*c;
            b[j][0] = b[j][0] + d;
        }
    }
    // for storing initial x value to 0
    for (i=0; i<n; i++){
        x[i][0] = 0;
    }
    // for finding x values
    for (i=n-1; i>=0; i--){
        sum = 0;
        for (j=i+1; j<n; j++){
            sum += a[i][j]*x[j][0];
        }
        x[i][0] = (b[i][0]-sum)/a[i][i];
        printf ("\n");
    }
    // for printing a matrix values
    printf ("Matrix after doing operation in A\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf ("%lf ", a[i][j]);
        }
        printf ("\n");
    }
    // for printing b value
    printf ("\nMatrix after doing operation in B\n");
    for (i=0; i<n; i++){
        printf ("%lf ", b[i][0]);
        printf ("\n");
    }
    // for printing x values
    printf ("\nMatrix storing X value\n");
    for (i=0; i<n; i++){
        printf ("%lf ", x[i][0]);
        printf ("\n");
    }
    return (0);
}

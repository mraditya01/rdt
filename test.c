#include <stdio.h>

/* The implementation of Gauss elimination. */
int main(){
    int i, j, k, c = 0;
    float result;
    float a[3][3], b[3], l[3][3], x[3]; /*making a 2 dimensional 3x3 array of "a" and "l", and making a 1 dimensional 3x1 array of "b" and "x"   */

    printf("Please enter A: "); /*inputting the element in the matrix A (row wise)*/
    for (i = 0; i < 3; i++){
	for (j = 0; j < 3; j++){
	    scanf("%f", &a[i][j]); /*scan the array element that inputted*/
	}
    }

    printf("please enter B: "); /*inputting the element in the matrix B (column wise)*/
    for (i = 0; i < 3; i++){
	scanf("%f", &b[i]); /*scan the array element that inputted*/
    }

    for (k = 0; k < 2; k++){
	/* cases in the Gaussian elimination. */
	if (a[k][k] == 0){
	    printf("Can't solve this linear equations by Gaussian-elimination.\n");/*case 1: where the element inputted is unsolvable which is when the array a have a dimension less than 3x3 or there exist a row and column where all of the number in the row and column are 0*/
	    return 1;
	}
	for (i = k+1; i < 3; i++){ /*if k>3*/
	    l[i][k] = a[i][k] / a[k][k]; /*divide each number in the row from matrix A by a number in matrix A matrix L is */
	    c++;
	}
	for (i = k+1; i < 3; i++){
	    for (j = k+1; j < 3; j++){
		a[i][j] = a[i][j] - l[i][k] * a[k][j];/*f*/
		c++;
	    }
	    b[i] = b[i] - l[i][k] * b[k];
	    c++;
	    a[i][k] = 0;
	}
    }

    printf("The solution to x is: ");
    x[2] = b[2] / a[2][2];/*f*/
    c++;
    for (i = 1; i >= 0; i--){
	result = 0.0;
	for (j = i+1; j < 3; j++){
	    result = result + a[i][j] * x[j];/*f*/
	    c++;
	}
	x[i] = (b[i] - result) / a[i][i]; /*f*/
	c++;
    }

    for (i = 0; i < 3; i++){
	printf("%.2f  ", x[i]);/*print the number in 2 float/2 decimal number*/
    }

    return 0;
}

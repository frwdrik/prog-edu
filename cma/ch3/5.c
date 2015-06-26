#include <stdio.h>

int main(void)
{
    int a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44;
    int rowSum1, rowSum2, rowSum3, rowSum4, diagonalSum1, diagonalSum2;

    printf("Enter the numbers from 0 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a11, &a12, &a13, &a14, &a21, &a22, &a23, &a24, &a31, &a32, &a33, &a34, &a41, &a42, &a43, &a44);

    rowSum1 = a11 + a12 + a13 + a14;
    rowSum2 = a21 + a22 + a23 + a24;
    rowSum3 = a31 + a32 + a33 + a34;
    rowSum4 = a41 + a42 + a43 + a44;
    diagonalSum1 = a11 + a22 + a33 + a44;
    diagonalSum2 = a14 + a23 + a32 + a41;

    printf("%-4.d%-4.d%-4.d%-4.d\n%-4.d%-4.d%-4.d%-4.d\n%-4.d%-4.d%-4.d%-4.d\n%-4.d%-4.d%-4.d%-4.d\n", a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44);
    printf("Row sums: %d %d %d %d\nDiagonal sums: %d %d\n", rowSum1, rowSum2, rowSum3, rowSum4, diagonalSum1, diagonalSum2);

    return 0;
}

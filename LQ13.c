/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: 
matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: 
[1,2,3,6,9,8,7,4,5]

Example 2:
Input: 
matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: 
[1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <stdio.h>
#include <stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int *result = (int *)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    int index = 0;
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = (*matrixColSize) - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            result[index++] = matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            result[index++] = matrix[i][right];
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    *returnSize = index;
    return result;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    printf("Enter number of rows (m) : ");
    scanf("%d", &m);
    printf("Enter number of columns (n) : ");
    scanf("%d", &n);
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        printf("Enter elements of row %d : ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int returnSize;
    int *result = spiralOrder(matrix, m, &n, &returnSize);
    printf("Spiral Order: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    free(result);
    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
*/
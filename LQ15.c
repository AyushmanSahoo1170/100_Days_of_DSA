/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.

Example 1:
Input: 
matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: 
[[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: 
matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: 
[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <stdio.h>
#include <stdlib.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int rowZero = 0, colZero = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        if (matrix[i][0] == 0)
            colZero = 1;
    }
    for (int j = 0; j < matrixColSize[0]; j++)
    {
        if (matrix[0][j] == 0)
            rowZero = 1;
    }
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 1; j < matrixColSize[0]; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 1; j < matrixColSize[0]; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (colZero)
    {
        for (int i = 0; i < matrixSize; i++)
            matrix[i][0] = 0;
    }
    if (rowZero)
    {
        for (int j = 0; j < matrixColSize[0]; j++)
            matrix[0][j] = 0;
    }
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    printf("Enter the number of rows (m) and columns (n) : ");
    scanf("%d %d", &m, &n);
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
    setZeroes(matrix, m, &n);
    printf("Matrix after setting zeroes : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
*/
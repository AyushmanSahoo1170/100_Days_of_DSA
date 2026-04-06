/*
Given a 2D integer array matrix, return the transpose of matrix. The transpose of a matrix is the matrix flipped over its main
diagonal, switching the matrix's row and column indices.

Example 1:
Input: 
matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: 
[[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: 
matrix = [[1,2,3],[4,5,6]]
Output: 
[[1,4],[2,5],[3,6]]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
*/

#include <stdio.h>
#include <stdlib.h>
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        (*returnColumnSizes)[i] = m;
    }
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
        printf("Enter elements of row %d separated by spaces: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int returnSize;
    int *returnColumnSizes;
    int **result = transpose(matrix, m, &n, &returnSize, &returnColumnSizes);
    printf("Transposed matrix:\n");
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < returnSize; i++)
    {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
*/
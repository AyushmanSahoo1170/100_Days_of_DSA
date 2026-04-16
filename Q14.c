/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix
in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix
*/

#include <stdio.h>
int isIdentityMatrix(int matrix[100][100], int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j && matrix[i][j] != 1) 
            {
                return 0;
            } 
            else if (i != j && matrix[i][j] != 0) 
            {
                return 0;
            }
        }
    }
    return 1;
}
int main() 
{
    int matrix[100][100], n;
    printf("Enter the size of the square matrix : ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix : \n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (isIdentityMatrix(matrix, n)) 
    {
        printf("Identity Matrix\n");
    } 
    else 
    {
        printf("Not an Identity Matrix\n");
    }
    return 0;
}
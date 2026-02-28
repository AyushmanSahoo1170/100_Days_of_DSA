/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include <stdio.h>
int main()
{
    int n, i, j = 0;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted elements of the array separated by space : ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Unique elements in the array : ");
    for (i = 1; i < n; i++) 
    {
        if (arr[i] != arr[j]) 
        {
            j++;
            arr[j] = arr[i];
        }
    }
    for (i = 0; i <= j; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
/*
You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array
represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing
element.

Examples:
Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.

Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size() + 1
*/

#include <stdio.h>
#include <stdlib.h>
int missingNum(int *arr, long long size)
{
    int total_sum = (size + 1) * (size + 2) / 2;
    long long arr_sum = 0;
    for (int i = 0; i < size; i++)
    {
        arr_sum = arr_sum + arr[i];
    }
    return total_sum - arr_sum;
}

/*
#include <stdio.h>  
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of the array (n-1): ");
    scanf("%d", &n);    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d distinct integers in the range from 1 to %d:\n", n, n + 1);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int total_sum = (n + 1) * (n + 2) / 2;
    int arr_sum = 0;
    for (int i = 0; i < n; i++) 
    {
        arr_sum = arr_sum + arr[i];
    }
    int missing_element = total_sum - arr_sum;
    printf("The missing element is: %d\n", missing_element);
    free(arr);
    return 0;
}
*/
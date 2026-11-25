/*
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of
nums[i].

Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:
Input: nums = [-1]
Output: [0]

Example 3:
Input: nums = [-1,-1]
Output: [0,0]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <stdio.h>
#include <stdlib.h>
int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    int size = 20002;
    int* tree = (int*)calloc(size + 1, sizeof(int));
    int* result = (int*)malloc(sizeof(int)*numsSize);
    for(int i=numsSize-1; i>=0; i--)
    {
        int index = nums[i] + 10001;
        int count = 0;
        int p = index - 1;
        while(p > 0)
        {
            count = count + tree[p];
            p = p - (p & -p);
        }
        result[i] = count;
        p = index;
        while(p <= size)
        {
            tree[p] = tree[p] + 1;
            p = p + (p & -p);
        }
    }
    free(tree);
    *returnSize = numsSize;
    return result;
}
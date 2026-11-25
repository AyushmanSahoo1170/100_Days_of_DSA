/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array
to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:
Input: 
nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: 
[3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: 
nums = [1], k = 1
Output: 
[1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include <stdio.h>
#include <stdlib.h>
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) 
{
    int *stack = (int*)malloc(sizeof(int) * numsSize);
    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int left = 0, right = 0;
    int index = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        while (left < right && nums[stack[right - 1]] < nums[i]) 
        {
            right--;
        }
        stack[right++] = i;
        if (stack[left] <= i - k) 
        {
            left++;
        }
        if (i >= k - 1) 
        {
            result[index++] = nums[stack[left]];
        }
    }
    *returnSize = index;
    free(stack);
    return result;
}
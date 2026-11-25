/*
Given an integer array nums and an integer k, return the kth largest element in the array. Note that it is the kth largest
element in the sorted order, not the kth distinct element. Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <stdio.h>
#include <stdlib.h>
int findKthLargest(int* nums, int numsSize, int k)
{
    int* count = (int*)calloc(20001, sizeof(int));
    for(int i=0; i<numsSize; i++)
    {
        count[nums[i] + 10000] = count[nums[i] + 10000] + 1;
    }
    int seen = 0;
    int answer = 0;
    for(int v=20000; v>=0; v--)
    {
        seen = seen + count[v];
        if(seen >= k)
        {
            answer = v - 10000;
            break;
        }
    }
    free(count);
    return answer;
}
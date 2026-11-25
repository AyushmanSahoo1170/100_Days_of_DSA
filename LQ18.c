/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums
except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. You must write an
algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: 
nums = [1,2,3,4]
Output: 
[24,12,8,6]

Example 2:
Input: 
nums = [-1,1,0,-3,3]
Output: 
[0,0,9,0,0]

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space
complexity analysis.)
*/

#include <stdio.h>
#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* answer = (int*)malloc(numsSize * sizeof(int));
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++)
        answer[i] = answer[i - 1] * nums[i - 1];
    int right_product = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        answer[i] *= right_product;
        right_product *= nums[i];
    }
    *returnSize = numsSize;
    return answer;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements of the array separated by spaces: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int returnSize;
    int *result = productExceptSelf(nums, n, &returnSize);
    printf("Product of array except self: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(nums);
    free(result);
    return 0;
}
*/
/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements. Note
that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 
Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 
Follow up: Could you minimize the total number of operations done?
*/

#include <stdio.h>
#include <stdlib.h>
void moveZeroes(int *nums, int numsSize)
{
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    for (int i = j; i < numsSize; i++)
    {
        nums[i] = 0;
    }
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
    moveZeroes(nums, n);
    printf("Array after moving zeroes to the end: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    free(nums);
    return 0;
}
*/
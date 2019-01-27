/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int *result = (int *)malloc(sizeof(int) * 2);

    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        int diff = target - nums[i];

        for (j = i + 1; j < numsSize; j++)
        {
            if (diff == nums[j])
            {
                result[0] = i;
                result[1] = j;
            }
        }
    }

    return result;
}
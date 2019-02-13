int maxSubArray(int *nums, int numsSize)
{
    int i;
    int max = nums[0];
    int tmp = 0;
    for (i = 0; i < numsSize; i++)
    {
        tmp += nums[i];
        if (tmp > max)
        {
            max = tmp;
        }

        if (tmp < 0)
        {
            tmp = 0;
        }
    }

    return max;
}
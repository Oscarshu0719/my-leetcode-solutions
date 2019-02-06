int removeElement(int nums, int numsSize, int val)
{
    int len = numsSize;

    int i = 0;
    int j;
    for (j = 0; j < len; j++)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

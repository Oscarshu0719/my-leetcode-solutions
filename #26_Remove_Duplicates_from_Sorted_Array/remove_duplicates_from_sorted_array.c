int removeDuplicates(int *nums, int numsSize)
{
    int *arr;
    arr = (int *)malloc(numsSize * sizeof(int));
    int index = 0;

    int i = 0;
    while (i < numsSize)
    {
        int tmp = nums[i];
        arr[index] = tmp;
        index++;

        int j = i;
        while (j < numsSize)
        {
            if (tmp == nums[j])
            {
                i = ++j;
            }
            else
            {
                break;
            }
        }
    }

    for (i = 0; i < index; i++)
    {
        nums[i] = arr[i];
    }

    return index;
}
void merge(int *nums1, int m, int *nums2, int n)
{
    if (m == 0)
    {
        int t;
        for (t = 0; t < n; t++)
        {
            nums1[t] = nums2[t];
        }
        
        return;
    }
    
    int j;
    int index = 0;
    int num = m;
    for (j = 0; j < n; j++)
    {
        int i;
        for (i = index; i < num; i++)
        {
            int k;
            if (nums2[j] <= nums1[i])
            {
                index = i;
                for (k = num; k > i; k--)
                {
                    nums1[k] = nums1[k - 1];
                }
                nums1[i] = nums2[j];
                num++;
                break;
            }

            if (i == num - 1)
            {
                nums1[num] = nums2[j];
                num++;
                break;
            }
        }
    }

    return;
}
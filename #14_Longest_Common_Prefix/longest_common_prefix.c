char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        return "";
    }

    char *result;

    int i;
    int min = strlen(strs[0]);
    for (i = 1; i < strsSize; i++)
    {
        min = (min > strlen(strs[i])) ? strlen(strs[i]) : min;
    }
    result = (char *)malloc(min * sizeof(char));
    memset(result, 0, sizeof(result));

    int j;
    for (i = 0; i < min; i++)
    {
        int flag = 1;
        for (j = 0; j < strsSize - 1; j++)
        {
            if (strs[j][i] != strs[j + 1][i])
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            result[i] = strs[0][i];
        }
    }

    return result;
}
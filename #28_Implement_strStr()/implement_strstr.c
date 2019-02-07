char *failure;

void failure_function(char *match)
{
    failure = (char *)malloc(strlen(match) * sizeof(char));
    // Stuff.
    failure[0] = -1;

    int i = -1;
    int j = 1;
    while (j < strlen(match))
    {
        while ((i > -1) && (match[i + 1] != match[j]))
        {
            i = failure[i];
        }

        if (match[j] == match[i + 1])
        {
            i++;
        }

        failure[j] = i;
        j++;
    }

    return;
}

int strStr(char *haystack, char *needle)
{
    if (strlen(needle) == 0)
    {
        return 0;
    }

    failure_function(needle);

    int i = -1;
    int j = 0;
    while (j < strlen(haystack))
    {
        while ((i > -1) && (needle[i + 1] != haystack[j]))
        {
            i = failure[i];
        }

        if (haystack[j] == needle[i + 1])
        {
            i++;
        }

        if (i == strlen(needle) - 1)
        {
            free(failure);
            return (j - i);
        }

        j++;
    }

    free(failure);
    return -1;
}
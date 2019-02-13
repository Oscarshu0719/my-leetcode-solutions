int lengthOfLastWord(char *s)
{
    if (strlen(s) == 0)
    {
        return 0;
    }

    int i;
    int len = 0;
    int last_len = 0;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            if (len != 0)
            {
                last_len = len;
            }
            len = 0;
        }
        else
        {
            len++;
        }
    }

    if (len != 0)
    {
        last_len = len;
    }

    return last_len;
}
bool isValid(char *s)
{
    char *tmp;
    tmp = (char *)malloc(strlen(s) * sizeof(char));
    memset(tmp, 0, sizeof(tmp));

    int index = 0;
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            tmp[index] = s[i];
            index++;
        }
        else if (s[i] == ')')
        {
            if (tmp[index - 1] == '(')
            {
                tmp[--index] = 0;
            }
            else
            {
                return 0;
            }
        }
        else if (s[i] == '}')
        {
            if (tmp[index - 1] == '{')
            {
                tmp[--index] = 0;
            }
            else
            {
                return 0;
            }
        }
        else if (s[i] == ']')
        {
            if (tmp[index - 1] == '[')
            {
                tmp[--index] = 0;
            }
            else
            {
                return 0;
            }
        }
    }

    if (tmp[0] != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}